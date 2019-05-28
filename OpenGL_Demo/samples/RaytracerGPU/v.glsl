#version 130
#line 41 /* "d:\\users\\wanxwang\\advanced_os\\graphic_pipeline\\opengl_demo\\samples\\raytracergpu\\raytracergpu.cpp" */
#define _DEBUG
uniform mat4 View;
uniform float Time;
out vec4 Color;

struct Object {
    int type;
    vec4 params;
    vec3 color;
    float diffuse;
};

struct Light {
    vec3 position;
    vec3 color;
};

Object Objects[] = Object[](
    Object(0, vec4(1, -0.8, -3, 2.5), vec3(0.7, 0.7, 0.0), 0.75),
    Object(0, vec4(-5.5, -0.5, -7, 2), vec3(0.7, 0.0, 0.1), 0.7),
    Object(1, vec4(0, 1, 0, 4.4), vec3(0.4, 0.3, 0.3), 1.0)
);

Light Lights[] = Light[](
    Light(vec3(0, 5, -5), vec3(0.6)),
    Light(vec3(2, 5, -1), vec3(0.7, 0.7, 0.9)),
    Light(vec3(0, 15, 0), vec3(0.8))
);

vec3 GetNormal(int object, vec3 p) {
    if (Objects[object].type == 0) {
        return (p - Objects[object].params.xyz) / Objects[object].params.w;
    }
    else {
        return Objects[object].params.xyz;
    }
}

float IntersectSphere(vec3 rO, vec3 rD, vec3 sC, float sR) {
    vec3 s = rO-sC;
    float b = 2*dot(s, rD);
    float c = dot(s, s)-sR*sR;
    float d = b*b-4*c;
    float t = -1;
    if (!(d < 0))
    {
        float min = 0.5 * (-b-sqrt(d));
        float max = 0.5 * (-b+sqrt(d));
        if (min > 0)
           t = min;
        else if (max > 0)
            t = max;
    }
    return t;
}

float IntersectPlane(vec3 rO, vec3 rD, vec3 pN, float pD) {
    float dp = dot(pN, rD);
    float d = -(dot(pN, rO) + pD) / dp;

    return d;
}

int IntersectObject(vec3 rO, vec3 rD, out float d) {
    float currDistance, minDistance = 100000.0;
    int minObject = -1;

    for (int i = 0; i < Objects.length(); ++i) {
        if (Objects[i].type == 0) {
            if ((currDistance = IntersectSphere(rO, rD, Objects[i].params.xyz, Objects[i].params.w)) >= 0
            && currDistance < minDistance)
            {
                minDistance = currDistance;
                minObject = i;
            }
        }
        else {
            if ((currDistance = IntersectPlane(rO, rD, Objects[i].params.xyz, Objects[i].params.w)) >= 0
            && currDistance < minDistance)
            {
                minDistance = currDistance;
                minObject = i;
            }
        }
    }

    d = minDistance;
    return minObject;
}

vec3 Shade(vec3 rO, vec3 rD, int object, vec3 p, vec3 n) {
    vec3 color = vec3(0);

    for (int i = 0; i < Lights.length(); ++i) {
        vec3 lightVec = Lights[i].position - p;
        vec3 l = normalize(lightVec);

        float sD;
        IntersectObject(p + l * 0.001, l, sD);

        if (length(lightVec) < sD) {
            float d = Objects[object].diffuse * max(dot(n, l), 0);
            color += d * Objects[object].color * Lights[i].color;
        }
    }

    return color;
}

vec3 Trace(vec3 rO, vec3 rD) {
    float d;
    int object = IntersectObject(rO, rD, d);

    if (object == -1) {
        return vec3(0);
    }

    vec3 p = rO + d * rD;
    vec3 n = GetNormal(object, p);
    return Shade(rO, rD, object, p, n);
}

void main() {
    vec4 orig = View * vec4(0, 0, 5, 1);
    float invWidth = 1.0 / 800.0;
    float invHeight = 1.0 / 600.0;
    float kcx = (gl_FragCoord.x * invWidth - 0.5) * 8;
    float kcy = (gl_FragCoord.y * invHeight - 0.5) * 6;
    vec4 rayO = View * vec4(kcx, kcy, 0, 1);
    vec3 rayD = normalize(rayO.xyz - orig.xyz);

    Objects[0].params.xz -= sin(Time) * cos(Time);
    Objects[1].params.xz += sin(Time) * cos(Time);
#ifndef _DEBUG
    Color = vec4(Trace(rayO.xyz, rayD), 1);
#else
    Color = vec4(0, 0, 0, 1);
    for (int i = 0; i < Objects.length(); ++i) {
        if (Objects[i].type == 0) {
            float t = IntersectSphere(rayO.xyz, rayD, Objects[i].params.xyz, Objects[i].params.w);
            if (t > 0)
            {
                Color = vec4(1, 1, 1, 1);
                break;
            }
        }
    }
#endif
}