from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

# Informasi router
router_domain = "http://192.168.18.1"
username = "Epuser"
password = "userEp"
device_ip = "192.168.18.25"

# Buka browser otomatis
driver = webdriver.Chrome()  # Pastikan Anda memiliki chromedriver
driver.get(router_domain)

# Login ke router
driver.find_element(By.ID, "username").send_keys(username)
driver.find_element(By.ID, "password").send_keys(password)
driver.find_element(By.ID, "login").click()

# Navigasi ke daftar perangkat dan hapus perangkat (sesuaikan dengan antarmuka router)
# Contoh ini tergantung pada struktur HTML router Anda
# driver.find_element(By.XPATH, "//button[text()='Disconnect']").click()