/*Gestione delle Coppie <chiave, valore>

Inserisci: Aggiunge una coppia <chiave, valore> al dizionario. (é giá implementata nel codice base)
Cancella: Rimuove una coppia dato il valore della chiave.
Recupera: Restituisce il valore associato a una chiave specifica. (é giá implementata nel codice base)
Appartiene: Verifica se una chiave è presente nel dizionario.
Stampa: Stampa il contenuto del dizionario in un formato leggibile. (é giá implementata nel codice base)*/


#include <iostream>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 100; // Dimensione fissa della tabella hash
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false;
    };

    Entry table[TABLE_SIZE];

    // Funzione hash di base
    int hashFunction(const std::string key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE; // Algoritmo di hashing semplice
        }
        return hash;
    }

public:
    // Metodo per aggiungere una coppia chiave-valore
    void inserisci(const std::string key, const T value) {
        int index = hashFunction(key);

        if (table[index].isOccupied) {
            std::cerr << "Collision detected for key: " << key << " at index " << index << ". Not handling collisions.\n";
            return;
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }

    //Rimuove una coppia dato il valore della chiave.
    void cancella(std::string key){
        int index = hashFunction(key);
         table[index].isOccupied = false;
    }

    // Metodo per ottenere il valore associato a una chiave
    T recupera(const std::string key) const {
        int index = hashFunction(key);

        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }

        return "Key not found!";
    }

    //Verifica se una chiave è presente nel dizionario.
    bool appartiene (std::string key){
        int index = hashFunction(key);
        if(table[index].key == key){
            return true;
        } else {
            return false;
        }
    }

    // Metodo per stampare il contenuto del dizionario
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }













};



















