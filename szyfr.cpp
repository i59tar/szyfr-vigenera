#include <iostream>
#include <string>
#include <fstream>

//a is ascii 97, z is 122

using namespace std;

string szyfr(string text, string cipher, string mode);
string crypto_prep(string src);

int main(int argc, char *argv[]){
if (argc<3) cout<<"Nieprawidlowa ilosc argumentow"<<endl;
else{
	string tryb;
	fstream tekst;
	tekst.open(argv[1]);
	if (!tekst.is_open()){
		cout<<"Nie powiodlo sie wczytywanie tekstu"<<endl;
		return 1;
	}
	string tresc ((istreambuf_iterator<char>(tekst)), istreambuf_iterator<char>());
	tresc = crypto_prep(tresc);
//wczytywanie tekstu
	fstream klucz;
	klucz.open(argv[2]);
	if (!klucz.is_open()){
		cout<<"Nie powiodlo sie wczytywanie klucza"<<endl;
		return 1;
	}
	string cardano ((istreambuf_iterator<char>(klucz)), istreambuf_iterator<char>());
	cardano = crypto_prep(cardano);
//wczytywanie klucza szyfrujacego			
	if(cardano.length()<tresc.length()) cardano.append(tresc);
	cardano.erase(tresc.length(),(cardano.length()-tresc.length()));			
	cout<<cardano<<endl;
//roszserzenie klucza, aby obejmowal calosc tresci
	if (argc==3){
		cout<<"Czy chcesz zaszyfrowac czy rozszyfrowac tekst? 'encr'/'decr'"<<endl;
		cin>>tryb;
	}
//opcja recznego wybierania trybu dzialania 'encr'/'decr'
	else tryb=argv[3];
	tekst.close();
	tekst.open(argv[1], std::fstream::out | std::fstream::trunc);
	if(tryb[0]=='e' || tryb[0]=='s' || tryb[0]=='z'){
		//pierwsze litery slow "encrypt" || "szyfruj" || "zaszyfruj"
		tresc = szyfr(tresc, cardano,"encr");
 		cout<<"Tekst zostal zaszyfrowany. Oto efekt: "<<endl<<tresc<<endl;
		tekst<<tresc;
		klucz.close();
		klucz.open(argv[2], std::fstream::out | std::fstream::trunc);
		klucz<<cardano;
		tekst.close();
		}
	else if(tryb[0]=='d' ||tryb[0]=='o' || tryb[0]=='r'){
		//pierwsze litery slow "decrypt" || "odszyfruj" || "rozszyfruj"
		tresc = szyfr(tresc, cardano, "decr");
 		cout<<"Tekst zostal rozszyfrowany. Oto efekt: "<<endl<<tresc<<endl;
		tekst<<tresc;
		klucz.close();
		tekst.close();
		}
	else cout<<"Nie rozpoznano trybu."<<endl;		
	}
return 0;
}

string szyfr(string text, string cipher, string mode){
	if (mode=="encr")for(size_t i=0;i<text.length()-1;i++) text[i]=((text[i]-97+(cipher[i]-97))%26)+97;
	else if(mode=="decr")for(size_t i=0;i<text.length()-1;i++) text[i]=((text[i]-71-(cipher[i]-97))%26)+97;
	return text;
}

string crypto_prep(string src)
{
    if (src.length() == 0) {
        return src;
    }

    for (size_t idx = 0;idx<src.length();idx++){
	if (src[idx]<65 ||(src[idx]>90 &&src[idx]<97) ||src[idx]>122) src=src.erase(idx--,1);

    }

    return src;
}

