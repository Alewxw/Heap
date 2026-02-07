Heap
	Este o structura de date, ce abstract poate fi vazuta ca un arbore binar care se completeaza pe fiecare nivel de la stanga la dreapta,  in care valorile nodurilor respecta o relatie intre parinti si copii. 
Heap-ul poate fi de tip max, valoarea fiecarui nod este mai mare sau egala decat valorile copiilor sai -> radacina e maximul ; de tip min, valoarea fiecarui nod este mai mica sau egala decat valorile copiilor sai -> radacina este minimul.
-	Stanga(i) = 2 * i
-	Parent(i) = i / 2
-	Dreapta(i) = 2 * i + 1

Acesta se foloseste pentru heap sort
-	Algoritm de sortare cu complexitate O(n log n)
-	Se construieste max-heap (n)-> radacina este pusa la finalul zonei nesortate, si tot scadem heapul
-	Max-heapify reface proprietatea heap-ului (log n)
-	Nu se foloseste spatiu suplimentar, se face in place

Priority queue
	O coada de prioritati este o structura de date asemanatoare cu coada obisnuita, insa fiecarui element ii este atribuita o prioritate, elementele fiind scoase in functie de prioritate, nu in ordinea adaugarii. Coada de prioritati poate fi implementata cu ajutorul heap-ului care ne ajuta sa pastram ordinea elementelor, fie cu prioritate maxima sau minima, permitand inserarea si extragerea elementelor in timp logaritmic.
