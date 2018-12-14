LogRaw = csvread('shadowmapping_matlab.csv');
[M, N] = size(LogRaw);
idx_frame = find(LogRaw(:,4)>0);
[M_prime,~] = size(idx_frame);
N_prime = N;
LogFrame = zeros(M_prime, N_prime);
i_r_d = 1;
for i_r_s = 1:M
    if (LogRaw(i_r_s, 4) > 0)
        LogFrame(i_r_d, :) = LogRaw(i_r_s,:);
        i_r_d = i_r_d + 1;
    end
end

FrameCnt = 1:M_prime;
CPUStart = LogFrame(:,1)';
h_deri = 0.5 * [-1 0 1];
CPUStart_deri = imfilter(CPUStart, h_deri, 'replicate');
SycDur = zeros(1, M_prime);
SycDur(1, 1) = 0;
SycDur(1, 2:M_prime) = LogFrame(1:M_prime-1, 3)';
%CPUStart_deri = CPUStart_deri - SycDur;
figure
subplot(2, 2, 1), plot(FrameCnt, CPUStart);
CPUDur = CPUStart(1, M_prime) - CPUStart(1, 1);
n_frame = M_prime - 1;
fps = round(n_frame/CPUDur*1000);
strTitle = sprintf('average fps = %d', fps);
title(strTitle);
xlabel('frame count'), ylabel('cpu time');
subplot(2, 2, 2), plot(FrameCnt, CPUStart_deri);
strMean = sprintf('mean = %f', mean(CPUStart_deri));
strStd = sprintf('standard divation = %f', std(CPUStart_deri));
title({'derivative of cpu time against frame count', ...
		strMean, ...
		strStd});
xlabel('frame count'), ylabel('cpu time');

GPUStart_deri = (LogFrame(:,4)/1000000)';
subplot(2, 2, 3), plot(FrameCnt, GPUStart_deri);
strMean = sprintf('mean = %f', mean(GPUStart_deri));
strStd = sprintf('standard divation = %f', std(GPUStart_deri));
title({'derivative of gpu time against frame count', ...
	strMean,...
	strStd});
xlabel('frame count'), ylabel('gpu time');


subplot(2, 2, 4), plot(FrameCnt, CPUStart_deri, 'r', ...
            FrameCnt, GPUStart_deri, 'b');
title({'derivative of cpu time against frame count (red)', ...
	'derivative of gpu time against frame count (blue)'});
xlabel('frame count'), ylabel('time');

