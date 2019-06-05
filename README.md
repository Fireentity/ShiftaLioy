<!DOCTYPE html>
<html>
<head>
</head>
<body>
<h2>
LA NOSTRA DOCUMENTAZIONE
</h2>
<div>
<p>
<strong>Indice generale</strong>
1. PARTE 1 
<li>1.1. Descrizione delle variabili 1</li>
<li>1.2. Parti sviluppate 1</li>
<li>2. Diario delle modifiche 2</li>
Documentazione di: Croce Lorenzo, Alikaj Marta, Dal Cero Davide<br>
Classe: 3BS<br>
<strong>1. PARTE 1</strong><br>
<h3>
1.1. Descrizione delle variabili
</h3>
Elencare le variabili e per ciascuna specificare il tipo e a cosa serve.<br>
<li> const int dim = 7: questa costante contiene un numero intero e viene inizializzata a
7. Indica la dimensione della griglia. La griglia sarà grande dim x dim caselle, quindi
7 x 7.</li>
<li> char griglia[dim][dim]: questa variabile è una matrice grande dim x dim (definito
precedentemente) caselle di tipo carattere. Le caselle conterranno solo i caratteri ‘x’
e ‘o’ , che rappresentano corrispettivamente le pedine inserite dai due giocatori.</li>
<li> string giocatore1: è una variabile che contiene una serie di caratteri char.</li>
<li>Giocatore1 contiene il nome o il soprannome del primo giocatore.</li>
<li> string giocatore2: come la variabile precedente, è una variabile che contiene una serie di caratteri char.</li>
<li>Giocatore2 contiene il nome o il soprannome del secondo giocatore.</li>
<li> bool fine=false: è una variabile di tipo bool che viene usata per controllare se il
gioco è finito o meno. Se fine = false allora il gioco non è finito e quindi continua, altrimenti termina.<li>
<li> char turno;: variabile di tipo char che stampa la lettera ‘x’ se a fare la mossa è
stato il primo giocatore. Altrimenti, mediante una funzione che cambia la ‘x’ in ‘o’,
stampa ‘o’.
<li>int riga: variabile di tipo intero che contiene il numero della riga scelta dal giocatore.</li>
<li> int colonna: variabile di tipo intero che contiene il numero, ovvero la posizione, della
colonna scelta dal giocatore.</li>

<em>Alikaj Marta, Croce Lorenzo, Dal Cero Davide- Liceo Lioy - A.S. 2018/19</em>

SECONDA PARTE DI VARIABILI:
<li> char vincitore: variabile di tipo char che una volta finito il gioco assume il nome
del giocatore che è riuscito a fare una linea di 5 caratteri uguali.</li>
<h3>
1.2. Parti sviluppate
</h3>
Spiego il ragionamento, e le strutture usate, di ogni singola funzione implementata.<br>
Già fatta come esempio:<br>
<li> void inizializzaGriglia(): pulisco la griglia la prima volta inserendo tutti caratteri
vuoti. Rispettivamente per ogni riga i, scorro ogni colonna j e assegno ad ogni
casella griglia[i][j] il carattere vuoto. La funzione non ha bisogno di parametri perché
va a modificare la griglia che è una variabile globale. La funzione non ritorna nulla
perché semplicemente deve modificare valori della griglia.</li>
<li> Inizializzare i nomi dei giocatori: una funzione di tipo void che chiede all’utente i nomi dei
giocatori.</li>
<li> Stampare la griglia completa: funzione di tipo void che controlla tutte le casella della
griglia se sono piene o meno. Ma mano che va avanti stampa tutte le caselle piene.</li>
<li> Chiedi la mossa al giocatore: chiedo al giocatore se vuole inserire il suo carattere in
una colonna o in una riga. Poi a seconda della sua risposta chiedo la posizione
della riga/colonna e in base alla risposta gli chiedo se vuole inserire la biglia
rispettivamente a destra o a sinistra, in basso in alto.</li>
<li> Aggiorno la griglia: dopo aver ricevuto una risposta completa da parte del giocatore
inserisco il suo carattere(x/o) dentro la casella. Abbiamo procurato le informazioni
della posizione precisa di essa grazie alla funzione precedente.</li>
<li> Controllo se la griglia è piena: Usando una funzione di tipo bool controllo se tutte le
caselle sono piene o meno.</li>
<li> Cambia il turno: Una funzione che cambia il turno dei giocatori basandosi sui
caratteri usati. Se prima il carattere inserito era l’x, quello successivo sarà l’o e così
via.</li<
<li> Mostra vincitore: una funzione che associando il carattere ‘x’ al primo giocatore e il
carattere ‘o’ al secondo controlla se è stata creata una linea continua caratterizzata
da uno dei due caratteri. Sa la linea è composta dai cinque caratteri ‘x’ allora la
funzione stampa come vincitore il giocatore x, altrimenti stampa il  giocatore o. </li>
<h3>
NUOVE FUNZIONI: 
</h3>
<li>ScorriC: scorre le colonne.</li>
<li>ControllaC: controlla se in una colonna ci sono 5 caselle uguali consecutive.</li>
<li>ControllaR: fa lo stesso ma in una riga.</li>
<li>Scorrir: Fa scorrere le righe.</li>
<li>Controllad1: controlla se nella diagonale che parte dalla casella al vertice alto e arriva alla casella in vertice basso ci sono 5 caselle uguali consecutive.</li>
<li>Controllad2:Stessa cosa ma con la diagonale dall’alato a sinistra al basso a destra.</li>
<li>Bool d1:controlla le diagonali più piccole con riga zero e colonna zero.</li>
<li>Bool d2: fa lo stesso con la diagonale con riga 1 e colonna zero.</li>
<li>Bool d3: diagonale con riga 5 e colonna zero.</li>
<li>Bool d4: diagonale con riga 6 e colonna 1.</li>
</p>
</div>
<footer>
<dl>Diario delle modifiche<br>
<dl>26/01/2017 Creazione del documento<br>
<dl> 09/02/2019 Aggiunta del capitolo Parte 1<br>
</footer>
</body>
</html>
