#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Virus {
public:
    string nama;
    vector<string> gejala;

    Virus(string n, vector<string> g) : nama(n), gejala(g) {}
};

void daftarVirus(Virus* viruses[], int size) {
    cout << "Daftar Virus:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << viruses[i]->nama << endl;
    }
}

bool periksaGejala(Virus* virus) {
    for (const auto& gejala : virus->gejala) {
        char jawaban;
        do {
            cout << "Apakah anda mengalami " << gejala << "? (y/n): ";
            cin >> jawaban;
            if (jawaban == 'y' || jawaban == 'Y') {
                break;
            } else if (jawaban == 'n' || jawaban == 'N') {
                return false;
            } else {
                cout << "Masukkan jawaban yang valid. 'y' untuk iya dan 'n' untuk tidak (y/n).\n";
            }
        } while (true);
    }
    return true;
}

int main() {
    Virus* viruses[] = {
        new Virus("COVID-19", {"Demam", "Batuk", "Sesak napas", "Mual, muntah, dan diare"}),
        new Virus("Flu", {"Demam", "Pilek", "Sakit tenggorokan", "Sakit kepala", "Lemas", "Tidak nafsu makan"}),
        new Virus("Ebola", {"Demam", "Mual dan muntah","Ruam pada kulit", "Diare yang disertai darah", "Perdarahan dari mata, telinga, hidung, dan anus"}),
        new Virus("HIV", {"Demam hingga menggigil", "Ruam di kulit", "Lelah", "Pembengkakan kelenjar getah bening", "Berkeringat di malam hari"}),
        new Virus("Hepatitis", {"Nyeri perut dan sendi", "Demam", "Kulit dan mata menguning", "Urine berwarna gelap", "Feses berwarna pucat"}),
        new Virus("Rabies", {"Demam menggigil", "Sakit kepala dan tenggorokan", "Hilang nafsu makan","Produksi air liur bertambah", "Sensitif terhadap cahaya", "Mengalami rasa takut yang berlebihan terhadap air"}),
        new Virus("Cacar", {"Demam dan sakit kepala", "Mual dan tidak nafsu makan", "Muncul benjolan merah di tubuh dan berubah menjadi lepuhan berisi cairan"}),
        new Virus("Campak", {"Demam, batuk, dan pilek", "Bintik putih kecil di dalam mulut", "Ruam merah di tubuh"})
    };

    int size = sizeof(viruses) / sizeof(viruses[0]);

    daftarVirus(viruses, size);

    int pilihvirus;
    bool inputValid;
    do {
        cout << "Pilih virus (1-" << size << "): ";
        cin >> pilihvirus;

        inputValid = pilihvirus >= 1 && pilihvirus <= size;

        if (!inputValid) {
            cout << "Pilihan tidak valid. Pilih angka (1-" << size << ")" << endl;
        }
    } while (!inputValid);

    Virus* virusDipilih = viruses[pilihvirus - 1];
    cout << "Anda memilih " << virusDipilih->nama << endl;

    if (periksaGejala(virusDipilih)) {
        cout << "\nPenyakit anda termasuk ke ciri-ciri " << virusDipilih->nama << endl;
        cout << "SEGERA PERIKSAKAN DIRI ANDA KE RUMAH SAKIT TERDEKAT UNTUK PENANGANAN LEBIH LANJUT." << endl;
    } else {
        cout << "\nAnda tidak menderita ciri-ciri " << virusDipilih->nama << "." << endl;
    }

    for (int i = 0; i < size; i++) {
        delete viruses[i];
    }

    return 0;
}