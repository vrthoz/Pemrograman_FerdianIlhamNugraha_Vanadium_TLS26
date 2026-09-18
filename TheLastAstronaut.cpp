#include <iostream>

int main() {
    int n, k;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> n;
    std::cout << "Masukkan nilai eliminasi awal (K): ";
    std::cin >> k;

    // Menggunakan alokasi array dinamis karena library bawaan tidak diperbolehkan
    bool* eliminated = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        eliminated[i] = false;
    }

    int remaining = n;
    int current_pos = 1;

    std::cout << "Urutan eliminasi: ";
    
    while (remaining > 1) {
        int count = 0;
        
        // Menemukan astronot ke-K yang masih hidup
        while (count < k) {
            if (!eliminated[current_pos]) {
                count++;
                if (count == k) {
                    break;
                }
            }
            if (count < k) {
                current_pos++;
                if (current_pos > n) {
                    current_pos = 1; // Memutar kembali ke awal lingkaran
                }
            }
        }

        // Eksekusi eliminasi
        eliminated[current_pos] = true;
        std::cout << current_pos << " ";

        // Pembaruan nilai K berdasarkan kondisi genap atau ganjil
        if (current_pos % 2 == 0) {
            k = k + 2;
        } else {
            k = k - 1;
        }
        
        // Memastikan nilai K tidak pernah kurang dari 2
        if (k < 2) {
            k = 2;
        }

        remaining--;

        // Mencari posisi astronot hidup selanjutnya untuk memulai perhitungan baru
        if (remaining > 0) {
            do {
                current_pos++;
                if (current_pos > n) {
                    current_pos = 1;
                }
            } while (eliminated[current_pos]);
        }
    }
    std::cout << "\n";

    // Mencari 1 astronot yang tersisa
    for (int i = 1; i <= n; i++) {
        if (!eliminated[i]) {
            std::cout << "Astronot terakhir yang bertahan: " << i << "\n";
            break;
        }
    }

    // Membersihkan memori
    delete[] eliminated;

    return 0;
}