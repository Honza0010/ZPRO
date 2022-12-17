Spojový seznam 
==============

Napište objektový spojový seznam pro prvek s obecnou datovou složkou typu <b>T</b>.

#### Metody

-   konstruktor <b>(0,5b)</b> - povinné

-   kopírovací konstruktor <b>(1,5b)</b>

-   destruktor <b>(1b)</b> - povinné

-   přidání prvku na začátek <b>(1b)</b> - povinné

-   odstranění prvního prvku <b>(1b)</b> - povinné

-   kontrola prázdnosti seznamu <b>(0,5b)</b> - povinné

-   přidání prvku na konec <b>(1b)</b>

-   odebrání posledního prvku <b>(1b)</b>

#### Bonusové metody

-   vrácení délky seznamu <b>(1b)</b>

-   otočení seznamu <b>(1b)</b>

-   metoda sort (setřídí seznam) <b>(1b)</b>

-   konstruktor s std::initializer_list<T> <b>(1b)</b>

Bonus (Iterátor) - (7b)
----------------

#### Metody seznamu

-   Vrácení iterátoru na začátek (hlavu) seznamu - metoda se musí nazývat begin() 

-   Vrácení iterátoru na konec (zarážku) seznamu - metoda se musí nazývat end()

#### Iterátor

-   konstruktor 

-   Posunutí iterátoru na další prvek seznamu (přetížit operátor
    ++) 

-   získat data z prvku uloženého v iterátoru (přetížit operátor
    \*) 
    
-   Porovnání, zda jsou dva iterátory stejné (přetížit operátor !=) 

Pokud chcete +2 body, můžete místo jednosměrného seznamu naimplementovat
obousměrný seznam. A další +3 body lze získat za šablonovou implementaci
seznamu.

Knihy 
=====

Máte textový soubor knihy.csv, který obsahuje na každém řádku údaje k
jedné knize (název, autor/ilustrátor, isbn, počet stránek, datum
publikace). Jednotlivé údaje na řádku jsou oddělené čárkou. Vaším úkolem
bude napsat funkci, která jednotlivé knihy ze souboru uloží do vhodného
kontejneru, který si vyberete (např. seznam, který si implementujete,
nebo knihovní std::list\<T\>). Dále bude za úkol napsat funkci (nebo metodu, pokud budete používat vlastní seznam), která
knihy seřadí podle počtu stránek/isbn v daném kontejneru (seznamu) a na
závěr bude funkce, která seznam uloží do textového souboru. Každá kniha
bude uložená na vlastním řádku ve specifikovaném pořadí (název
knihy-autor/ilustrátor-isbn-počet stran-datum publikace)

#### Funkce

-   Načtení knih do seznamu <b>(4b)</b>

-   Seřazení knih podle daného parametru <b>(5b)</b>

-   Uložení knih ze seznamu do textového souboru <b>(3b)</b>

Abyste dostali za tuto úlohu body, musí fungovat všechny 3 funkce.
    
Podmínky k udělení zápočtu 
==========================

Podmínkou k udělení zápočtu je zisk alespoň 20 bodů. K bodům ze
zápočtové úlohy Vám budou přičteny i body z domácích úloh.

Zápočtovou úlohu vypracujte nejlépe do konce zkouškového období.

Programy ke kontrole posílejte tehdy, kdy půjdou přeložit a nebudou
házet žádné chybové hlášení. Stejně tak dávejte do svého zdrojového kódu
komentáře, abyste vystihli, co daná část kódu dělá a jak to dělá, aby
bylo vidět, že jste to někde jen neopsali, aniž byste tomu rozuměli.

