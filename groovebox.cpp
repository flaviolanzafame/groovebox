#include <iostream>
#include <string>
using namespace std;
int main() {
	// --- DICHIARAZIONE DELLE VARIABILI ---
	// Variabili per memorizzare i dati di 5 brani (titolo, artista, durata, anno, ascolti)
	string titolo1 = " ", titolo2 = " ", titolo3 = " ", titolo4 = " ", titolo5 = " ";
	string artista1, artista2, artista3, artista4, artista5;
	string temp_disp, cerca;
	int durata1 = 0, durata2 = 0, durata3 = 0, durata4 = 0, durata5 = 0;
	int anno1, anno2, anno3, anno4, anno5;
	int stream1 = 0, stream2 = 0, stream3 = 0, stream4 = 0, stream5 = 0;
	// Variabili di gestione: contatore brani, scelte e durata playlist
	int numeroBrani = 0, scelta = 0, durataTotale = 0, bScelto = 0;
	// Variabili booleane per la disponibilita' dei brani
	bool disponibile1 = false, disponibile2 = false, disponibile3 = false, disponibile4 = false, disponibile5 = false, branoTrovato = false;
	do {
		// Menu' principale mostrato all'utente
		cout << "\n------ Groovebox ------" << endl;
		cout << "1. Aggiungi brano alla playlist" << endl;
		cout << "2. Riproduci playlist" << endl;
		cout << "3. Cerca brano per titolo" << endl;
		cout << "4. Modifica disponibilita' brano" << endl;
		cout << "5. Statistiche playlist" << endl;
		cout << "6. Elimina ultimo brano" << endl;
		cout << "7. Esci" << endl;
		// Blocco per la scelta dell'opzione con controllo dell'errore (Input Validation)
		do {
			cout << "\nScegli un'opzione: ";
			if (!(cin >> scelta) || scelta < 1 || scelta > 7) {
				cout << "Errore: opzione non valida." << endl;
				cin.clear();  // Pulisce lo stato di errore del buffer di input
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Rimuove i caratteri residui nel buffer
				scelta = 0;
			}
		} while (scelta < 1 || scelta > 7);
		// --- GESTIONE DELLE OPZIONI TRAMITE SWITCH ---
		switch (scelta) {
		case 1: // Aggiungi brano alla playlist
			if (numeroBrani >= 5) {
				cout << "Errore: playlist piena." << endl;
			} else {
				// Sotto-switch per assegnare i dati alla variabile corretta (da 1 a 5)
				switch (numeroBrani) {
				case 0:
					cout << "\n--- Brano 1---" << endl;
					// Pulizia buffer prima di getline per evitare il salto dell'input
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Titolo: ";
					getline(cin, titolo1);
					cout << "Artista: ";
					getline(cin, artista1);
					// Validazione della durata inserita (deve essere tra 30 e 600 secondi)
					do {
						durata1 = 0;
						cout << "Durata (30-600 s): ";
						cin >> durata1;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					} while (durata1 < 30 || durata1 > 600);
					do {
						cout << "Disponibile (si/no): ";
						getline(cin, temp_disp);
					} while (temp_disp != "si" && temp_disp != "no");
					disponibile1 = (temp_disp == "si");
					// Controllo anno: se disponibile deve essere nel passato, altrimenti nel futuro
					if (disponibile1) {
						do {
							anno1 = 0;
							cout << "Anno di pubblicazione: ";
							cin >> anno1;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno1 < 1700 || anno1 > 2026);
					} else {
						do {
							anno1 = 0;
							cout << "Anno di uscita previsto: ";
							cin >> anno1;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno1 < 2026);
					}
					break;
				case 1:
					cout << "\n--- Brano 2---" << endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Titolo: ";
					getline(cin, titolo2);
					cout << "Artista: ";
					getline(cin, artista2);
					do {
						durata2 = 0;
						cout << "Durata (30-600 s): ";
						cin >> durata2;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					} while (durata2 < 30 || durata2 > 600);
					do {
						cout << "Disponibile (si/no): ";
						getline(cin, temp_disp);
					} while (temp_disp != "si" && temp_disp != "no");
					disponibile2 = (temp_disp == "si");
					if (disponibile2) {
						do {
							anno2 = 0;
							cout << "Anno di pubblicazione: ";
							cin >> anno2;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno2 < 1700 || anno2 > 2026);
					} else {
						do {
							anno2 = 0;
							cout << "Anno di uscita previsto: ";
							cin >> anno2;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno2 < 2026);
					}
					break;
				case 2:
					cout << "\n--- Brano 3---" << endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Titolo: ";
					getline(cin, titolo3);
					cout << "Artista: ";
					getline(cin, artista3);
					do {
						durata3 = 0;
						cout << "Durata (30-600 s): ";
						cin >> durata3;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					} while (durata3 < 30 || durata3 > 600);
					do {
						cout << "Disponibile (si/no): ";
						getline(cin, temp_disp);
					} while (temp_disp != "si" && temp_disp != "no");
					disponibile3 = (temp_disp == "si");
					if (disponibile3) {
						do {
							anno3 = 0;
							cout << "Anno di pubblicazione: ";
							cin >> anno3;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno3 < 1700 || anno3 > 2026);
					} else {
						do {
							anno3 = 0;
							cout << "Anno di uscita previsto: ";
							cin >> anno3;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno3 < 2026);
					}
					break;
				case 3:
					cout << "\n--- Brano 4---" << endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Titolo: ";
					getline(cin, titolo4);
					cout << "Artista: ";
					getline(cin, artista4);
					do {
						durata4 = 0;
						cout << "Durata (30-600 s): ";
						cin >> durata4;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					} while (durata4 < 30 || durata4 > 600);
					do {
						cout << "Disponibile (si/no): ";
						getline(cin, temp_disp);
					} while (temp_disp != "si" && temp_disp != "no");
					disponibile4 = (temp_disp == "si");
					if (disponibile4) {
						do {
							anno4 = 0;
							cout << "Anno di pubblicazione: ";
							cin >> anno4;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno4 < 1700 || anno4 > 2026);
					} else {
						do {
							anno4 = 0;
							cout << "Anno di uscita previsto: ";
							cin >> anno4;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno4 < 2026);
					}
					break;
				case 4:
					cout << "\n--- Brano 5---" << endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Titolo: ";
					getline(cin, titolo5);
					cout << "Artista: ";
					getline(cin, artista5);
					do {
						durata5 = 0;
						cout << "Durata (30-600 s): ";
						cin >> durata5;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					} while (durata5 < 30 || durata5 > 600);
					do {
						cout << "Disponibile (si/no): ";
						getline(cin, temp_disp);
					} while (temp_disp != "si" && temp_disp != "no");
					disponibile5 = (temp_disp == "si");
					if (disponibile5) {
						do {
							anno5 = 0;
							cout << "Anno di pubblicazione: ";
							cin >> anno5;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno5 < 1700 || anno5 > 2026);
					} else {
						do {
							anno5 = 0;
							cout << "Anno di uscita previsto: ";
							cin >> anno5;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} while (anno5 < 2026);
					}
					break;
				}
				numeroBrani++; // Incremento contatore brani caricati
				cout << "Brano aggiunto con successo!" << endl;
			}
			break;
		case 2: // Riproduci playlist
			// Blocco per mostrare tutti i brani caricati finora
			if (numeroBrani == 0) {
				cout << "La playlist e' vuota." << endl;
			} else {
				cout << "\n--- RIPRODUZIONE PLAYLIST ---" << endl;
				if (numeroBrani >= 1) {
					cout << "1. " << titolo1 << " - " << artista1 << " (" << durata1 << " s) ";
					if (disponibile1) {
						cout << "[" << anno1 << "]" << endl;
						stream1++; // Incremento contatore ascolti
					} else
						cout << "[Non disponibile. Esce nel " << anno1 << "]" << endl;
				}
				if (numeroBrani >= 2) {
					cout << "2. " << titolo2 << " - " << artista2 << " (" << durata2 << " s) ";
					if (disponibile2) {
						cout << "[" << anno2 << "]" << endl;
						stream2++;
					} else
						cout << "[Non disponibile. Esce nel " << anno2 << "]" << endl;
				}
				if (numeroBrani >= 3) {
					cout << "3. " << titolo3 << " - " << artista3 << " (" << durata3 << " s) ";
					if (disponibile3) {
						cout << "[" << anno3 << "]" << endl;
						stream3++;
					} else
						cout << "[Non disponibile. Esce nel " << anno3 << "]" << endl;
				}
				if (numeroBrani >= 4) {
					cout << "4. " << titolo4 << " - " << artista4 << " (" << durata4 << " s) ";
					if (disponibile4) {
						cout << "[" << anno4 << "]" << endl;
						stream4++;
					} else
						cout << "[Non disponibile. Esce nel " << anno4 << "]" << endl;
				}
				if (numeroBrani >= 5) {
					cout << "5. " << titolo5 << " - " << artista5 << " (" << durata5 << " s) ";
					if (disponibile5) {
						cout << "[" << anno5 << "]" << endl;
						stream5++;
					} else
						cout << "[Non disponibile. Esce nel " << anno5 << "]" << endl;
				}
			}
			break;
		case 3: // Cerca brano
			// Blocco per la ricerca testuale all'interno dei titoli inseriti
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Cerca brano: ";
			cin >> cerca;
			getline(cin, cerca);
			/* titoloX.find(cerca) restituisce la posizione della parola se trovata,
			   altrimenti restituisce string::npos */
			if (titolo1.find(cerca) != string::npos)  {
				cout << "Trovato: " << titolo1 << " " << artista1 << " (" << durata1 << " s) [" << anno1 << "]" << endl;
				branoTrovato = true;
			}
			if (titolo2.find(cerca) != string::npos) {
				cout << "Trovato: " << titolo2 << " " << artista2 << " (" << durata2 << " s) [" << anno2 << "]" << endl;
				branoTrovato = true;
			}
			if (titolo3.find(cerca) != string::npos) {
				cout << "Trovato: " << titolo3 << " " << artista3 << " (" << durata3 << " s) [" << anno3 << "]" << endl;
				branoTrovato = true;
			}
			if (titolo4.find(cerca) != string::npos) {
				cout << "Trovato: " << titolo4 << " " << artista4 << " (" << durata4 << " s) [" << anno4 << "]" << endl;
				branoTrovato = true;
			}
			if (titolo5.find(cerca) != string::npos) {
				cout << "Trovato: " << titolo5 << " " << artista5 << " (" << durata5 << " s) [" << anno5 << "]" << endl;
				branoTrovato = true;
			}
			if (branoTrovato == false) {
				cout<<"Brano non trovato, riprova."<<endl;
			}
			break;
		case 4: // Modifica disponibilita'
			// Blocco per invertire lo stato disponibile/non disponibile (Toggle)
			if (numeroBrani == 0) {
				cout << "Playlist vuota." << endl;
			} else {
				cout << "Inserisci numero brano da modificare: ";
				cin >> bScelto;
				if (bScelto >= 1 && bScelto <= numeroBrani) {
					switch (bScelto) {
					case 1:
						disponibile1 = !disponibile1;
						break;
					case 2:
						disponibile2 = !disponibile2;
						break;
					case 3:
						disponibile3 = !disponibile3;
						break;
					case 4:
						disponibile4 = !disponibile4;
						break;
					case 5:
						disponibile5 = !disponibile5;
						break;
					}
					cout << "Stato aggiornato." << endl;
				} else {
					cout << "Errore: Selezione non valida." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					bScelto = 0;
				}
			}
			break;
		case 5: // Statistiche
			// Calcolo della durata totale sommando i valori e calcolo della media
			cout << "\n------ STATISTICHE ------\n";
			durataTotale = durata1 + durata2 + durata3 + durata4 + durata5;
			cout << "Brani in playlist: " << numeroBrani << endl;
			cout << "Durata totale: " << durataTotale << " s" << endl;
			if (numeroBrani > 0)
				cout << "Durata media: " << durataTotale / numeroBrani << " s" << endl;
			// Algoritmo di confronto per determinare il brano con piu' stream
			cout<<"Brano piu' ascoltato: ";
			if (stream1 > stream2 && stream1 > stream3 && stream1 > stream4 && stream1 > stream5)
				cout << titolo1 << " - " << artista1 << endl;
			else if (stream2 > stream1 && stream2 > stream3 && stream2 > stream4 && stream2 > stream5)
				cout << titolo2 << " - " << artista2 << endl;
			else if (stream3 > stream1 && stream3 > stream2 && stream3 > stream4 && stream3 > stream5)
				cout << titolo3 << " - " << artista3 << endl;
			else if (stream4 > stream1 && stream4 > stream2 && stream4 > stream3 && stream4 > stream5)
				cout << titolo4 << " - " << artista4 << endl;
			else if (stream5 > stream1 && stream5 > stream2 && stream5 > stream3 && stream5 > stream4)
				cout << titolo5 << " - " << artista5 << endl;
			else
				cout << "/" << endl;
			break;
		case 6: // Elimina ultimo brano
			// Rimuove logicamente l'ultimo brano inserito decrementando il contatore
			if (numeroBrani > 0) {
				numeroBrani--;
				cout << "\nUltimo brano rimosso correttamente." << endl;
			} else
				cout << "\nErrore: la playlist e' gia' vuota." << endl;
			break;
		}
	} while (scelta != 7); // Uscita dal programma
	cout << "\nGrazie per aver usato Groovebox!" << endl;
	return 0;
}
