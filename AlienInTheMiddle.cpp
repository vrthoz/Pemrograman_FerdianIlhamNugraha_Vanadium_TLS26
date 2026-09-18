#include <iostream>

// User-defined function pengganti library bawaan untuk menghitung panjang array karakter
int customStringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    // Array statis yang cukup besar karena std::string tidak diperbolehkan
    char pesan_asli[1000];
    
    std::cout << "Masukkan pesan asli (huruf kapital, tanpa spasi): ";
    std::cin >> pesan_asli;

    int len = customStringLength(pesan_asli);
    char pesan_sandi[1000];

    // Mengamankan kondisi jika input tidak kosong
    if (len > 0) {
        pesan_sandi[0] = pesan_asli[0]; // Huruf pertama selalu tetap
        pesan_sandi[len] = '\0';        // Menandai akhir array pembentukan sandi
    }

    // Memproses huruf ke-2 hingga selesai
    for (int i = 1; i < len; i++) {
        // Konversi dari ASCII murni ('A'=65) ke angka urutan murni (1 hingga 26)
        int val_sekarang = pesan_asli[i] - 'A' + 1;
        
        // Menggunakan huruf dari pesan ASLI sebelumnya, bukan yang sudah dienkripsi
        int val_sebelum = pesan_asli[i - 1] - 'A' + 1;

        int val_baru = val_sekarang + val_sebelum;

        // User-defined proses perputaran kembali ke 'A' jika melewati 'Z'
        while (val_baru > 26) {
            val_baru -= 26;
        }

        // Restorasi pengembalian ke nilai karakter ASCII
        pesan_sandi[i] = (char)(val_baru - 1 + 'A');
    }

    std::cout << "Pesan sandi: " << pesan_sandi << "\n";

    return 0;
}