#include <iostream>
#include <random>
#include <string>

using namespace std;

string BarangSSR[] = { "V-Power-Nitro", "pertamax-Turbo", "Vivo-Revvo95"};
string BarangSR[] = { "Pertamax", "V-Power", "Vivo-Revvo92" };
string BarangR[] = { "Pertalite", "Shell-Super", "Vivo-Revvo89" };




// fungsi pengacakan index pada array

int PengacakIndex(int Max_item) {
	random_device Random;// on off random 
	unsigned int seed = Random();
	mt19937 MesinPengacak(seed); // membuat angka di acaka
	uniform_int_distribution<int> Rentan_Index(0, Max_item - 1); // rentan dari index item pada array

	return Rentan_Index(MesinPengacak); // kembalikan nilai index pada fungsi
}

// fungsi gacha

string gacha() {
	random_device Random;
	unsigned int seed = Random();
	mt19937 Mesin_pengacak(seed);
	uniform_int_distribution<int> Rentan_Gacha(0, 100);
	

	Rentan_Gacha(Mesin_pengacak);

	if (Rentan_Gacha(Mesin_pengacak) <= 5.0) {
		return " Selamat " + BarangSSR[PengacakIndex(3)] + " SSR " ;
	} 
	else if(Rentan_Gacha(Mesin_pengacak) <= 20.0) {
		return " Selamat : " + BarangSR[PengacakIndex(3)] + " SR ";
	}
	else{

	    return " Selamat : " +  BarangR[PengacakIndex(3)] + " R ";
	}
	

}



	

int main() {
	int saldo;
	int jumlah_gacha_diminta;
	int harga_gacha = 5000;
	int jumlah_gacha_sebenarnya;
	char x;
	int total1 = 0;


	cout << " === SELAMAT DATANG DI SPBU GACOR === " << endl << endl;

	do {

			cout << " Masukan mau gacha berapa kali : ";
			cin >> jumlah_gacha_diminta;
			cout << endl;

			cout << "<==== PASTIKAN  DI TIKET ATAS 5000 ====>\n";
			cout << "masukan Tiket anda : ";
			cin >> saldo;

			// mengatur jumlah gacha
			int maks_gacha = saldo / harga_gacha;
			jumlah_gacha_sebenarnya = min(jumlah_gacha_diminta, maks_gacha);

			
			if (jumlah_gacha_sebenarnya == 0) {
			cout << "saldo anda tidak memenuhi" << endl;
			}
			else {
				cout << "jumlah gacha yang mencukupi : " << jumlah_gacha_sebenarnya << endl;
			}


			for (int i = 1; i <= jumlah_gacha_sebenarnya; i++){
				 total1 = 1 + total1;

				if (total1 == 20) {
					cout << "Selamat Anda mendapatkan " << BarangSSR[PengacakIndex(3)] << "  SSR " << endl;
					total1 = 0; // meriset pitty
				}
				else {
					cout << "putaran ke- " << i << " : Selamat Anada mendapatkan " << gacha() << "pitty : " << total1 << "/20" << endl;
				}
				saldo -= harga_gacha;
				cout << endl;
				
			}
		cout << "Sisa Saldo anda : " << saldo << endl;
		cout << "apakah ingin lanjut? (y/Y) : (no) jika tidak : " ;
		cin >> x;


	} while (x == 'y' || x == 'Y');


	cout << endl << endl;
	cout << "terima kasih telah bermain";

	




	cin.get();
	return 0;
}
