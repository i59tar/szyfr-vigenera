# szyfr-vigenera
Szyfr Vigenere'a. Język - C/C++

# Manual:
- Program działa w terminalu.
- przyjmuje 2 argumenty: adres tekstu i adres klucza
- 3 argument jest opcjonalny: tryb działania: szyfrowanie/odszyfrowanie. Opcjonalny, bo można o tym zadecydować w trakcie działania programu
- Po kolei: przetwarza ciąg znaków w plikach, aby zawierały tylko małe litery alfabetu (bez znaków diakrytycznych, spacji, etc.)
- 	    Dopasowuje klucz, aby był równy długości tekstu
- 	    Przeprowadza szyfrowanie/rozszyfrowanie względem spreparowanego klucza
- 	    Zapisuje nowy tekst i nowy klucz w plikach tekstowych.

Version 0.2:
- Przetworzono algorytm kodowania. Do tej pory on korzystał z autoklucza (klucz uzupełniany później samym tekstem)


Funkcjonalność do uzupełnienia:

-	wielkie litery
-	możliwość wprowadzenia ciągów tekstowych jako argumenty zamiast adresów plików tekstowych
