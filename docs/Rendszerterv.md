# UNIDEB MINORS
## Rendszerterv  


### Bevezetés  

A program/játék célja, hogy részben leváltsa a népszerű
Scrabble játék analóg (klasszikus társasjáték) változát,
és növelje a játék játékosainak számát. Ehhez a játékhoz
szükséges megvásárolnunk a klasszikis társasjátékot, viszont
ennek a szoftvernek a segítségével betekintést nyerhetnek a 
későbbi felhasználók. Először is interneten elérhetővé válna
ennek a játéknak a próbaverziója, amely segítségével kipróbálhatná
a felhasználó a játékot. Ez segíthet abban, hogy döntést tudjunk
hozni: megvásároljuk a számítógépes verziót, a klasszikus tátsasjátékot,
esetleg nem szeretnénk egyiket sem, mivel nem tetszett a próbaverzió
során a játék. A próbaverzió sokaknak nyújt nagy segítséget, mivel
nem kell sok pénzt költenünk egy olyan játékra, ami lehet, hogy nem is
tetszik nekünk.
A fejlesztés során Debian alapú linux disztribúciót használtunk (Ubuntu),
viszont a későbbiekben szeretnénk játszhatóvá tenni más platformokon.
A gépeink hardverje legalább 8DB RAM-ból, Intel Core i5-7500HQ 2.20GHz
típusú processzorból és NVIDIA dedikált videókártyákból állnak. A gépek
számára biztosítva van stabil internetelérés, viszont a játék internet
nélkül, heli hálózaton játszható, akár egy számítógépen is.
A játék felépítése szerver-kliens alapú, szükséges egy szervert
nyitnunk, majd annak a segítségével tud kommunikálni a lokális
hálózaton a két kliens egymással.

  
### A rendszer célja  

A rendszer vélja, hogy népszerűsítse, illetve részben leváltsa
a jól ismert Scrabble játékot. A mai fiatalok sokkal könnyebben
tudnának megismerkedni az alapjátékkal, ha esetleg találkoznak
vele az interneten, barátaikkal ki tudják próbálni azt.
A szoftver az egyszerűséget is hivatott elhozni, hiszen nehéz
megszervezni egy több fős baráti társaságat, mindenki egy helyen
kell, hogy legyen, viszont ennek a szoftvernek a segítségével
nem lenne szükséges elhagyni az otthon kényelmét és melegét.
    
### Projekt terv

A szoftver célja a klasszikus értelemben vett társasjáték
egy részében történő leváltása, megkönnyítése
  
###  Projektszerepkörök és felelősségeik

A projektben résztvevő felek minden tekintetben egyenrangúak,
viszont a scrum módszert követve megválasztásra került az ún.
Teamleader, aki a projekt koordinálását végzi, viszont a fejlesztői
szerepkörben is ugyanúgy kiveszi a részét

Név |   Szerepkör
-----------|---------
Magyar Zsolt | Teamleader, szoftverfejlesztő, szoftvertesztelő
Ferenczi Péter  | szoftverfejlesztő, szoftvertesztelő
Czibere Tamás    | szoftverfejlesztő, szoftvertesztelő
  
### Ütemterv  

Négy részre bontjuk a menetet

- Dokumentácio
- Szoftver megírása
- Tesztelés
- Hiba javítás

### Mérföldkövek
Fő mérföldkövek:

- Trello létrehozása
- Git repo letrehozása és be linkelése trelloba1
- Doksi megfelelő elkészítése
- Program elkészítése
- Program tesztelése
- Program esetleges hibáinak javítása

  
###  Üzleti szereplők  

A programot, illetve játékot bárki használhatja, aki
rendelkezik bizonyos előtudással (a késöbbeikben a játék
mellé fogunk csatolni egy játékszabályt is).
Az ingyenes próbaverziót bárki játszhatja, a teljes verziót
viszont csak az, aki megvásárolja azt. A program használatához
semmiféle előképzettség nem szükséges, minden funkciója
felhasználó közeli, a játékszabályok ismerete elég a
megfelelő játék előidézéséhez.
  
###  Üzleti folyamatok

Példa üzleti folyamatra lokális hálózaton:
- szerver elindítása terminál ablakban
- kliens1 elindítása külön terminál ablakban
- kliens2 elindítása külön terminál ablakban
- kliens1 elkezdheti a játékot
- kliens2 folytatja a játékot

A játék végén:
A kliensek bezárása után bezárhatjuk a szerver terminál ablakát
 
###  Üzleti entitások  
  
Az üzletben lévő entitások:
- A játékot játszó két ellenfél
  
### Követelmények  


  
### Funkcionális követelmények  
  

  
###  Nem funkcionális követelmények  
  

  
### Funkcionális terv  


  
### Rendszerszereplők  


  
### Fizikai környezet  


  
### Fejlesztő eszközök  


  
### Architekturális terv  


   
### Egy architekturális tervezési minta  
  
 
  
### Az alkalmazás rétegei, fő komponensei, ezek kapcsolatai  


  
### Rendszer bővíthetősége  
  


### Biztonsági funkciók  


   
### Implementációs terv  


  
### Üzleti logika osztályai  


  
### Tesztterv  

Kód|Leírás|  
----|---  
T01: |Szerver elindítása
T02: |Első kliens elindítása 
T03: |Második kliens elindítása 
T04: |Socketelés megfelelő működésének ellenőrzése 
T05: |Loopback cím kihagyása 
T06: |Először kliensek, majd szerver bezárása 
T07: |Először szerver, majd kliensek bezárása 
T08: |Változók tartalmának helyes kiolvasása a memóriából
T09: |Játék logikája
T10: |Beírt szó szó-e
T11: |A beírt szó betűi a listában vannak-e
T12: |Szó kezdetének koordinátája benne van-e a táblában
T13: |Szó kezdetének a koordinátájához illeszthető-e az adott betű
T14: |Irány megadása
T15: |Irány megadásának ellenőrzése
T16: |A szó kifér-e a táblába
T17: |A szó betűi ha illeszkednek másra, akkor megfelelőek-e