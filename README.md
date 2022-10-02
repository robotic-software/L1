## Robotic-software Lezione 1

#### Esempio 1.1: esempio di compilazione

        $ 1.1/src
        
1. Compilare con i seguenti comandi:

        $ cd 1.1/src
        $ gcc -o hello hello.cc
        
    Eseguire con 
        
        $ ./hello
        
2. Compilare con 
    
        $ cd 1.1/src
        $ make
        
    Eseguire con 
        
        $ ./hello

3. Compilare con i seguenti comandi:

        $ cd 1.1
        $ mkdir build && cd build
        $ cmake .. 
        $ make



#### Esempio 2.1: esempio di utilizzo libreria boost

Compilare con
        
        $ cd 2.1
        $ mkdir build && cd build
        $ cmake .. 
        $ make

Eseguire con 

        $ ./bin/es2.1
        
#### Esempio 3.1: esempio di controllore PID multi-thread

Compilare con
        
        $ cd 3.1
        $ mkdir build && cd build
        $ cmake .. 
        $ make

Eseguire con 

        $ ./bin/es3.1
        
Inserire l'ingresso di controllo desiderato da linea di comando

#### Esempio 4.1: esempio script in python
Script per la somma di due numeri, prima inseriti da codice, poi richiesti da tastiera

#### Esempio 5.1: esempio di script in python
Script per la definizione di una classe Persona con 3 attributi in python

#### Esempio 6.1: esempio di script in python
Script per l'esecuzione multi-threading di una funzione python. Una funzione accetta un numero in ingresso che ne identifica l'attesa prima di concluderne l'esecuzione




