#pragma once

enum class Turno {BLANCO, NEGRO};
//he mirado y pone que el enum class es mas limpio y seguro que el enum normal

// cambio de turno
inline Turno cambiar_turno(Turno actual) {
    return (actual == Turno::BLANCO) ? Turno::NEGRO : Turno::BLANCO;
}

// Comprobaciones
inline bool es_blanco(Turno t) {
    return t == Turno::BLANCO;
}

inline bool es_negro(Turno t) {
    return t == Turno::NEGRO;
}

// Representación en texto
inline const char* a_string(Turno t) {
    return (t == Turno::BLANCO) ? "Blanco" : "Negro";
}