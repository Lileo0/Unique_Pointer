// Unique_Pointer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "UniquePtr.h"
#include "UniquePtr.cpp" //Main findet cpp nicht??
#include "String.h" //Included wegen Tests
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Sprint 1") {
    struct Entity {
        int id = -1;
    };
    struct CustomDeleter {
        void operator()() {

        }
    };

    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<String> stringPointer(new String("Hello World"));
    CHECK(entityPointer->id != 0);
    CHECK(stringPointer->c_str() != 0);
}

TEST_CASE("Copy Constructor") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<Entity> entityPointer2(entityPointer);
    UniquePtr<Entity> entityPointer3 = entityPointer;
    CHECK(entityPointer.Get() != entityPointer2.Get());
    CHECK(entityPointer.Get() != entityPointer3.Get());
}
TEST_CASE("Copy Assignment") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<Entity> entityPointer2;
    entityPointer2 = entityPointer;
    CHECK(entityPointer.Get() != entityPointer2.Get());
}
TEST_CASE("Move Constructor") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<Entity> entityPointer2(std::move(entityPointer));
    CHECK(entityPointer.Get() == nullptr);
    CHECK(entityPointer2.Get() != nullptr);
}
TEST_CASE("Move Assignment") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<Entity> entityPointer2;
    entityPointer2 = std::move(entityPointer);
    CHECK(entityPointer.Get() == nullptr);
    CHECK(entityPointer2.Get() != nullptr);
}
TEST_CASE("RESET") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    entityPointer.Reset();
    CHECK(entityPointer.Get() == 0);
}

TEST_CASE("RELEASE") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    Entity* temp = entityPointer.Release();
    CHECK(entityPointer.Get() == 0);
    CHECK(temp != 0);
}

TEST_CASE("SWAP") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    Entity* entityPointer2 = new Entity;
    Entity* temp = entityPointer.Get();
    Entity* temp2 = entityPointer2;
    entityPointer.Swap(entityPointer2);
    CHECK(entityPointer.Get() == temp2);
    CHECK(entityPointer2 == temp);;
}

TEST_CASE("SWAP2") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<Entity> entityPointer2(new Entity);
    Entity* temp = entityPointer.Get();
    Entity* temp2 = entityPointer2.Get();
    entityPointer.Swap(entityPointer2);
    CHECK(entityPointer.Get() == temp2);
    CHECK(entityPointer2.Get() == temp);;
}

TEST_CASE("BOOL") {
    struct Entity {
        int id = -1;
    };
    UniquePtr<Entity> entityPointer(new Entity);
    CHECK(entityPointer);
    entityPointer.Reset();
    CHECK(!entityPointer);
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
