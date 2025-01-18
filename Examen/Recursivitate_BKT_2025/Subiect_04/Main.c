/*
	Un labirint este reprezentat sub forma unei matrice A cu m linii și n coloane. 
	
	Elementele A[i][j] reprezintă informația legată de acea celulă:

								−1: perete,

								0: celulă liberă,

								>0: puncte de energie.

	Se presupune că un roboțel se găsește inițial într-o celulă A(a,b), având P puncte de energie. 
	
	Știind că roboțelul consumă un punct de energie la fiecare pas și că acesta se poate deplasa atâta vreme cât 
	
	mai are energie disponibilă, să se implementeze structurile de date necesare și funcțiile valid și soluție pentru 
	
	un algoritm de tip backtracking care:

		Calculează toate traseele ce pot fi urmate de roboțel pentru ca el să iasă din labirint 
		
		(să ajungă în oricare din celulele libere de la marginea labirintului).

	Roboțelul se poate deplasa în oricare din cele 4 celule învecinate (sus, jos, stânga, dreapta), 
	
	cu condiția ca acestea să nu fie un perete, iar dacă celula conține puncte de energie atunci le va culege, 
	
	încărcându-și bateriile.
*/