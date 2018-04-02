function [bestEpsilon bestF1] = selectThreshold(yval, pval)
%SELECTTHRESHOLD Find the best threshold (epsilon) to use for selecting
%outliers
%   [bestEpsilon bestF1] = SELECTTHRESHOLD(yval, pval) finds the best
%   threshold to use for selecting outliers based on the results from a
%   validation set (pval) and the ground truth (yval).
%

bestEpsilon = 0;
bestF1 = 0;
F1 = 0;

stepsize = (max(pval) - min(pval)) / 1000;
for epsilon = min(pval):stepsize:max(pval)
    
    % ====================== YOUR CODE HERE ======================
    % Instructions: Compute the F1 score of choosing epsilon as the
    %               threshold and place the value in F1. The code at the
    %               end of the loop will compare the F1 score for this
    %               choice of epsilon and set it to be the best epsilon if
    %               it is better than the current choice of epsilon.
    %               
    % Note: You can use predictions = (pval < epsilon) to get a binary vector
    %       of 0's and 1's of the outlier predictions

    predictions = (pval < epsilon);
    f = zeros(4, 1);
    m = size(yval, 1);
    for i = 1 : m
        if yval(i, 1) == 1
            if predictions(i, 1) == 1
                f(1, 1) += 1;
            else
                f(2, 1) += 1;
            end;
        else
            if predictions(i, 1) == 1
                f(3, 1) += 1;
            else
                f(4, 1) += 1;
            end;
        end;
    end;
    if (f(1, 1) + f(2, 1)) != 0
        t1 = 1.0 * f(1, 1) / (f(1, 1) + f(2, 1));
    else
        t1 = 0;
    end;
    if (f(1, 1) + f(3, 1)) != 0
        t2 = 1.0 * f(1, 1) / (f(1, 1) + f(3, 1));
    else
        t2 = 0;
    end;
    if (t1 + t2) != 0
        F1 = 2 * (t1 * t2) / (t1 + t2);
    else
        F1 = 0;
    end;






    % =============================================================

    if F1 > bestF1
       bestF1 = F1;
       bestEpsilon = epsilon;
    end
end

end
