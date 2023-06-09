# Stack Machine



## Informacje

Projekt: Stack Machine

Autor: Dominika Boguszewska

## Uruchomienie programu

Program został napisany w Visual Studio 2022, zatem owe środowisko jest potrzebne do jego uruchomienia.

## Podział pracy

W wyniku braku komunikacji między członkami zespołu, wszystko zostało napisane przez Dominikę Boguszewską.

## Użyte biblioteki

Program nie wykorzystuje bibliotek spoza standardowych bibliotek języka C++.

## Użycie programu

Po uruchomieniu programu pojawi się menu w konsoli, które pozwoli nam odczytać wcześniej zapisany stos z pliku tekstowego lub stworzyć nowy stos dla naszej maszyny stosowej. Niestety na dzień dzisiejszy main programu obsługuje tylko maszynę stosową typu int.

Po stworzeniu maszyny stosowej, ukaże nam się menu z operacjami, które możemy dokonać na naszym stosie:

1. addition - dodaje dwa ostatnie elementy na stosie,
2. subtraction - odejmuje dwa ostatnie elementy na stosie,
3. multiplication - mnoży dwa ostatnie elementy na stosie,
4. division - dzieli dwa ostatnie elementy na stosie,
5. bitwise and - wykonuje logiczne and między kolejnymi bitami dwóch ostatnich elementów na stosie,
6. bitwise or - wykonuje logiczne or między kolejnymi bitami dwóch ostatnich elementów na stosie,
7. bitwise xor - wykonuje logiczne xor między kolejnymi bitami dwóch ostatnich elementów na stosie,
8. bitwise not - wykonuje logiczne not na ostatnim elemencie na stosie,
9. duplicate - duplikuje ostatni element na stosie,
10. swap - zamienia miejsca dwóch ostatnich elementów na stosie,
11. push - dodaje na stos element podany przez użytkownika,
12. pop - usuwa ze stosu ostatni element,
13. clear - czyści cały stos,
14. save to file - zapisuje stos do pliku podanego przez użytkownika,
15. exit - pozwala użytkownikowi wyjść z programu.

