1;

clc; clear; close all;

A = [2,  1, -1;
    -3, -1,  2;
    -2,  1,  2];
b = [8; -11; -3];

fprintf('=== 1. UJI AKURASI SOLUSI (Matriks 3x3) ===\n');

x_manual = gauss_jordan_manual(A, b);
fprintf('Hasil Gauss-Jordan Manual :\n'); disp(x_manual');

Aug_rref = rref([A, b]);
x_rref = Aug_rref(:, end);
fprintf('Hasil rref() Bawaan       :\n'); disp(x_rref');

x_backslash = A \ b;
fprintf('Hasil Operator Backslash  :\n'); disp(x_backslash');
fprintf('===========================================\n\n');


fprintf('=== 2. MENGHITUNG KECEPATAN (UKURAN MATRIKS N x N) ===\n');
sizes = [10, 50, 100, 200, 300];

waktu_manual = zeros(size(sizes));
waktu_rref   = zeros(size(sizes));
waktu_slash  = zeros(size(sizes));

for i = 1:length(sizes)
    N = sizes(i);
    A_big = rand(N, N) * 10;
    b_big = rand(N, 1) * 10;

    tic;
    x1 = gauss_jordan_manual(A_big, b_big);
    waktu_manual(i) = toc;

    tic;
    Aug_big = rref([A_big, b_big]);
    x2 = Aug_big(:, end);
    waktu_rref(i) = toc;

    tic;
    x3 = A_big \ b_big;
    waktu_slash(i) = toc;

    fprintf('Selesai menguji matriks ukuran %d x %d\n', N, N);
end


figure('Name', 'Perbandingan Performa Metode Numerik');
plot(sizes, waktu_manual, '-or', 'LineWidth', 2, 'MarkerFaceColor', 'r'); hold on;
plot(sizes, waktu_rref, '-sg', 'LineWidth', 2, 'MarkerFaceColor', 'g');
plot(sizes, waktu_slash, '-^b', 'LineWidth', 2, 'MarkerFaceColor', 'b');
hold off;

grid on;
xlabel('Ukuran Matriks (N x N)', 'FontSize', 11, 'FontWeight', 'bold');
ylabel('Waktu Eksekusi (Detik)', 'FontSize', 11, 'FontWeight', 'bold');
title('Grafik Perbandingan Kecepatan Komputasi', 'FontSize', 13, 'FontWeight', 'bold');
legend('Gauss-Jordan Manual', 'rref() Bawaan', 'Backslash (\\)', 'Location', 'NorthWest');


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
