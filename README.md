# segmented_least_square
This is cpp code for the famous problem of segmented least sqaure which states as follows:
Given n points in x-y plane we need to compute the line(s) that  minimise the error where error is given as
ERROR=summation over i where i varies from 0 to n-1 (yi-axi-b)^2
and also there is an constant that we have to add in the error.
where a and b are given by formula calculated by partial differentiation of the ERROR equation.

Now approach is partition the points into contiguos segments and calcute the errors for partial segments to calculate the final ERROR.since there can be non differentiable points where passing only one line would give terrible error so we would have to take 2 lines or 3 or more lines depending on number of non-differentiable points which we cannot be determined easily so we would have to check every possible partitions.And the constant has to be multiplied by number of segments aalso,
