#ifndef _LIBGLTRACER_H
#define _LIBGLTRACER_H
#ifndef TRACEGL
#define TRACEGL_1(func, p1)\
	printf("name=%s, file=%s, line=%d\n", #func, __FILE__, __LINE__);\
	func(p1)
#endif
#define TRACEGL_VOID_1(func, p1)\
	printf("S:name=%s, file=%s, line=%d\n", #func, __FILE__, __LINE__);\
	func(p1);\
	printf("E\n");

#define TRACEGL_VOID_3(func, p1, p2, p3)\
	printf("S:name=%s, file=%s, line=%d\n", #func, __FILE__, __LINE__);\
	func(p1, p2, p3);\
	printf("E\n");





#endif