#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

// Lista dei prototipi delle funzioni che verranno implementate sotto il main
void inizializzaGiocatori(string& g1, string& g2);
void inizializzaGriglia(char griglia[][7], int dim);
void chiediRigaColonna(string giocatore, char&scelta_riga_colonna, char &scelta_direzione, int &scelta_numero_riga_colonna, char griglia[][7], const int dim);

// ... da aggiungere quelle fatte da voi
void selezione_colore(string &colore, string giocatore);
void shift_r(char a[][7], const int dim, int index, int riga);
void shift_l(char a[][7], const int dim, int index, int riga);
void shift_b(char a[][7], const int dim, int index, int colonna);
void shift_h(char a[][7], const int dim, int index, int colonna);
int trovaSpazio_destra(char a[][7], int riga, const int dim);
int trovaSpazio_sinistra(char a[][7], int riga, const int dim);
int trovaSpazio_alto(char a[][7], int colonna, const int dim);
int trovaSpazio_basso(char a[][7], int colonna, const int dim);
void stampaGriglia(char griglia[][7], const int dim, string colore1, string colore2);
bool grigliaPiena(char griglia[][7], const int dim);
void cambiaTurno(char &turno);
void aggiornaGriglia(char griglia[][7], const int dim, char scelta_riga_colonna, char scelta_direzione, int scelta_numero_riga_colonna, char turno);

int main(){
		
	
	// Griglia e dimensioni
	const int dim = 7;
	char griglia[dim][dim];
	
	// Giocatori
	string giocatore1;
	string giocatore2;
	
	//colori dei giocatori
	string colore1;
	string colore2;
	
	// Stato del gioco
	bool fine=false;
	
	// Turno attuale: 'x' oppure 'o'
	char turno = 'x';
	
	// Scelta riga/colonna del giocatore
	char scelta_riga_colonna = 0;
	// Scelta direzione
	char scelta_direzione;
	// Scelta del numero di riga/colonna
	int scelta_numero_riga_colonna;
	
	
	// Vincitore: ' ' -> pari, 'x' -> giocatore 1, 'o' -> giocatore 2
	char vincitore = 0;
	
	// 1) Pulisco la griglia la prima volta inserendo tutti caratteri vuoti
	inizializzaGriglia(griglia, dim);
	
	// 2) Inizializzare i nomi dei giocatori
	inizializzaGiocatori(giocatore1, giocatore2);
	
	//selezione colore giocatori
	selezione_colore(colore1, giocatore1);
	cout<<endl;
	selezione_colore(colore2, giocatore2);
	
	// 3) Stampare la griglia completa
	system("cls");
	cout<<"\e[0;31m_________SHIFTALIOY_________\e[0m"<<endl<<endl;
	// Finchè il gioco non è finito continua a far giocare i 2 giocatori
	while(fine==false){
		stampaGriglia(griglia, dim, colore1, colore2);
		cout<<endl;
		// 4) Chiedi la mossa al giocatore
		string giocatore;
		if(turno == 'x')
			giocatore=giocatore1;
		else
			giocatore=giocatore2;
		chiediRigaColonna(giocatore, scelta_riga_colonna, scelta_direzione, scelta_numero_riga_colonna,griglia, dim);
		
		// 5) Aggiorno la stato griglia (eseguo lo shift)
		aggiornaGriglia(griglia, dim, scelta_riga_colonna, scelta_direzione, scelta_numero_riga_colonna, turno);
		// 6) Controllo se la griglia è piena
		fine = grigliaPiena(griglia, dim);
		// 7) Controllo eventuale vittoria DA NON IMPLEMENTARE NELLA PARTE 1 DEL PROGETTO
		
		// 8) Cambia il turno
		cambiaTurno(turno);
		system("cls");
		cout<<"\e[0;31m_________SHIFTALIOY_________\e[0m"<<endl<<endl;
	}
	
	// 9) Mostra vincitore
}

// -------------------- IMPLEMENTAZIONE DELLE FUNZIONI --------------------

//seleziona i colori dei giocatori
void selezione_colore(string &colore, string giocatore) {
	int colore_giocatore;
	cout<<"Rosso(1), Verde(2), Giallo(3), Blue(4), Magenta(5), Ciano(6), Bianco(7)"<<endl;
	cout<<giocatore<<" inserisci il colore che vuoi: ";
	cin>>colore_giocatore;
	switch(colore_giocatore) {
		case 1:
			colore = "\e[0;31m";
		break;
		case 2:
			colore = "\e[0;32m";
		break;
		case 3:
			colore = "\e[0;33m";
		break;
		case 4:
			colore = "\e[0;34m";
		break;
		case 5:
			colore = "\e[0;35m";
		break;
		case 6:
			colore = "\e[0;36m";
		break;
		case 7:
			colore = "\e[0;37m";
		break;
	}
}

// 1) Pulisco la griglia la prima volta inserendo tutti caratteri vuoti
void inizializzaGriglia(char griglia[][7], int dim){
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			griglia[i][j]=' ';
		}
	}
}


// 2) Inizializzare i nomi dei giocatori
void inizializzaGiocatori(string& g1, string& g2){
		cout<<"Inserire il nome del giocatore 1"<<": ";
		cin>>g1;
		cout<<"Inserire il nome del giocatore 2"<<": ";
		cin>>g2;
		cout<<endl<<"Pronti per la sfida:\t"<<g1<<" vs "<<g2<<endl<<endl;
}	

// 3) Stampare la griglia completa
void stampaGriglia(char griglia[][7], const int dim, string colore1, string colore2) {
	cout<<"+---+---+---+---+---+---+---+"<<endl;
	for(int i = 0; i < dim; i ++) {
		cout<<"| ";
		for(int j = 0; j < dim; j++) {
			if(griglia[i][j] == 'x') {
				cout<<colore1<<griglia[i][j]<<"\e[0;37m | ";
			} else {
				cout<<colore2<<griglia[i][j]<<"\e[0;37m | ";
			}
		}
		cout<<endl<<"+---+---+---+---+---+---+---+"<<endl;
	}
}

// 4) Chiedi la mossa al giocatore

//verifica se una riga è piena
bool rigaPiena(int riga, char griglia[][7], const int dim) {
	bool piena = true;
	int cont = 0;
	while(cont < dim && piena) {
		if(griglia[riga][cont] == ' ') {
			piena = false;
		}
		cont++;
	}
	return piena;
}

//verifica se una colonna è piena
bool colonnaPiena(int colonna, char griglia[][7], const int dim) {
	bool piena = true;
	int cont = 0;
	while(cont < dim && piena) {
		if(griglia[cont][colonna] == ' ') {
			piena = false;
		}
		cont++;
	}
	return piena;
}

void chiediRigaColonna(string giocatore, char&scelta_riga_colonna, char &scelta_direzione, int &scelta_numero_riga_colonna, char griglia[][7], const int dim){
	cout<<giocatore<<" vuoi inserire la biglia in una riga o in una colonna (r/c): ";
	cin>>scelta_riga_colonna;
	
	// chiedi se da destra o da sinistra/ alto o basso
	if(scelta_riga_colonna=='r')
		cout<<giocatore<<" quale riga vuoi selezionare (1-7): ";
	else
		cout<<giocatore<<" quale colonna vuoi selezionare (1-7): ";
	cin>>scelta_numero_riga_colonna;
	
	while(rigaPiena(scelta_numero_riga_colonna, griglia, dim) && scelta_riga_colonna == 'r') {
		cout<<"Seleziona una riga non piena (1-7): ";
		cin>>scelta_numero_riga_colonna;
	}
	
	while(colonnaPiena(scelta_numero_riga_colonna, griglia, dim) && scelta_riga_colonna == 'c') {
		cout<<"Seleziona una colonna non piena (1-7): ";
		cin>>scelta_numero_riga_colonna;
	}
	scelta_numero_riga_colonna--;
	
	// chiedi se da destra o da sinistra/ alto o basso
	if(scelta_riga_colonna=='r')
		cout<<giocatore<<" vuoi inserire da destra o da sinistra (s/d): ";
	else
		cout<<giocatore<<" vuoi inserire dall'alto o dal basso (a/b): ";
	cin>>scelta_direzione;
}


// 5) Aggiorno la griglia

//shift a destra
void shift_r(char a[][7], const int dim, int index, int riga) {
	for (int i=index; i>0 ; i--){ 
		a[riga][i] = a[riga][i-1];
	} 
}

//shift a sinistra
void shift_l(char a[][7], const int dim, int index, int riga) {
	for (int i=index; i<dim ; i++){ 
		a[riga][i] = a[riga][i+1];
	} 
}

//shift in basso
void shift_b(char a[][7], const int dim, int index, int colonna)
{
	for(int i=index; i>0; i--)
	{
		a[i][colonna]=a[i-1][colonna];
	}
}

//shift in alto
void shift_h(char a[][7], const int dim, int index, int colonna)
{
	for (int i=index; i<dim ; i++)
	{ 
		a[i][colonna] = a[i+1][colonna];
	} 
}

//trova l'indice del primo spazio a destra
int trovaSpazio_destra(char a[][7], int riga, const int dim)  {
	int cont = dim-1;
	bool spazio = false;
	while(cont > 0 && !spazio){
		if(a[riga][cont] == ' ') {
			spazio = true;
		} else {
			cont--;
		}
	}
	return cont;
}

//trova l'indice del primo spazio in alto
int trovaSpazio_alto(char a[][7], int colonna, const int dim) {
	int cont = 0;
	bool spazio = false;
	while(cont < dim && !spazio){
		if(a[cont][colonna] == ' ') {
			spazio = true;
		} else {
			cont++;
		}
	}
	return cont;
}

//trova l'indice del primo spazio in basso
int trovaSpazio_basso(char a[][7], int colonna, const int dim) {
	int cont = dim-1;
	bool spazio = false;
	while(cont > 0 && !spazio){
		if(a[cont][colonna] == ' ') {
			spazio = true;
		} else {
			cont--;
		}
	}
	return cont;
}

//trova l'indice del primo spazio a sinistra
int trovaSpazio_sinistra(char a[][7], int riga, const int dim)  {
	int cont = 0;
	bool spazio = false;
	while(cont < dim && !spazio){
		if(a[riga][cont] == ' ') {
			spazio = true;
		} else {
			cont++;
		}
	}
	return cont;
}

//aggiorna la griglia ed esegue gli shift
void aggiornaGriglia(char griglia[][7], const int dim, char scelta_riga_colonna, char scelta_direzione, int scelta_numero_riga_colonna, char turno) {
	if(scelta_riga_colonna == 'r') {
		if(scelta_direzione == 's') {
			shift_r(griglia, dim, trovaSpazio_sinistra(griglia, scelta_numero_riga_colonna, dim), scelta_numero_riga_colonna);
			griglia[scelta_numero_riga_colonna][0] = turno;
		} else {
			shift_l(griglia, dim, trovaSpazio_destra(griglia, scelta_numero_riga_colonna, dim), scelta_numero_riga_colonna);
			griglia[scelta_numero_riga_colonna][dim-1] = turno;
		}
	} else {
		if(scelta_direzione == 'b') {
			shift_h(griglia, dim, trovaSpazio_basso(griglia, scelta_numero_riga_colonna, dim), scelta_numero_riga_colonna);
			griglia[dim-1][scelta_numero_riga_colonna] = turno;
		} else {
			shift_b(griglia, dim, trovaSpazio_alto(griglia, scelta_numero_riga_colonna, dim), scelta_numero_riga_colonna);
			griglia[0][scelta_numero_riga_colonna] = turno;
		}
	}
}

// 6) Controllo se la griglia è piena
bool grigliaPiena(char griglia[][7], const int dim) {
	int i = 0, j = 0;
	while(i < dim && griglia[i][j] != ' ') {
		j=0;
		while(j< dim && griglia[i][j] != ' ') {
			j++;
		}
		i++;
	}
	return griglia[i][j] != ' ';
}
// 7) Controllo eventuale vittoria DA NON IMPLEMENTARE NELLA PARTE 1 DEL PROGETTO
		
// 8) Cambia il turno
void cambiaTurno(char &turno) {
	turno = turno == 'x' ? 'o' : 'x';
}
	
// 9) Mostra vincitore
