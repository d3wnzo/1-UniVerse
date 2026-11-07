from sklearn.linear_model import LinearRegression

X_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Y_data = [120, 115, 110, 105, 100, 95, 90, 85, 80, 75]

X_data = [[x] for x in X_list] 

model = LinearRegression()
model.fit(X_data, Y_data) 

m = model.coef_[0]    
c = model.intercept_ 

print("--- Hasil Komputasi Firing Solution (Y = mX + c) ---")
print(f"Koefisien (m): {m:.2f}") 
print(f"Intercept (c): {c:.2f}") 

X_prediksi = [[11], [12]]
Y_prediksi = model.predict(X_prediksi)

print("\n--- Prediksi Penjualan ---")
print(f"Prediksi Periode ke-11: {Y_prediksi[0]:.0f} unit")
print(f"Prediksi Periode ke-12: {Y_prediksi[1]:.0f} unit")

BEP_Y = 65
X_BEP = (BEP_Y - c) / m

print("\n--- Titik Nol Profit (BEP = 65 unit) ---")
print(f"Toko diprediksi masuk zona kerugian di awal Periode Taktis ke-: {X_BEP:.1f}")