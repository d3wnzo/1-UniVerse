function x = gauss_jordan_manual(A, b)
    [m, n] = size(A);
    Aug = [A, b];

    for i = 1:m
        [~, max_idx] = max(abs(Aug(i:m, i)));
        pivot_row = max_idx + i - 1;

        if pivot_row ~= i
            Aug([i, pivot_row], :) = Aug([pivot_row, i], :);
        end

        pivot = Aug(i, i);
        if abs(pivot) < 1e-9
            error('Matriks singular atau tidak memiliki solusi unik.');
        end
        Aug(i, :) = Aug(i, :) / pivot;

        for j = 1:m
            if i ~= j
                faktor = Aug(j, i);
                Aug(j, :) = Aug(j, :) - faktor * Aug(i, :);
            end
        end
    end

    x = Aug(:, end);
end
