import os

# Perintah untuk menghapus entri ARP untuk IP tertentu di router
# (pastikan Anda memiliki hak akses root atau admin)
ip_device = "192.168.1.8"
os.system(f"arp -d {ip_device}")