#include <iostream>
#include <istream>
#include <string>

#include "world.hpp"
#include "list.hpp"

using namespace std;

void Data::print( SNPtr _pAIL ){
    if ( _pAIL == NULL ) cout << "{ }";
    else{
        cout << "{ ";
        while( _pAIL != NULL ){
            cout << _pAIL->miData << " ";
            _pAIL = _pAIL->mpNext;
        }
        cout << "}";
    }
}

int Data::length( SNPtr _pAIL ){   
    auto i(0u);
    while( _pAIL != NULL ){
        i++;
        _pAIL = _pAIL->mpNext;
    }
    return i;
}

bool Data::empty( SNPtr _pAIL ){ return _pAIL == NULL; }

void Data::clear( SNPtr & _pAIL ){
    while ( _pAIL != NULL ){
        SNPtr save = _pAIL;
        delete [] _pAIL;        
        _pAIL = save->mpNext;
    }
}

bool Data::front( SNPtr _pAIL, int & _retrievedVal ){
    if (_pAIL != NULL){
        _retrievedVal = _pAIL->miData;
        return true;
    }
    return false;
}

bool Data::back( SNPtr _pAIL, int & _retrievedVal ){
    if ( _pAIL == NULL ) return false;
    while ( _pAIL != NULL ){
        _retrievedVal = _pAIL->miData;
        _pAIL = _pAIL->mpNext;
    }
    return true;
}

bool Data::pushFront( SNPtr & _pAIL, int _newVal ){
    SNPtr start;
    try{ start = new Node; }
    catch( const std::bad_alloc & e ){ return false; }
    start->miData = _newVal; // Recebe o valor
    start->mpNext = _pAIL; // Aponta para o antigo primeiro ou para NULL.
    _pAIL = start; // Head aponta para o novo primeiro.
    return true;
}

bool Data::pushBack( SNPtr & _pAIL, int _newVal ){
    if ( _pAIL == NULL )
        pushFront( _pAIL, _newVal );
    else{
        //SNPtr end;
        SNPtr aux = _pAIL; // Auxiliar para salvar endereço do head.
        // Vai até o último elemento.
        while ( _pAIL->mpNext != NULL ){
            _pAIL = _pAIL->mpNext;
        }
        if( pushFront( _pAIL->mpNext, _newVal ) )
            _pAIL = aux; // Devolve o endereço do head.
        else
            return false;
    }
    return true;
}


bool Data::popFront( SNPtr & _pAIL, int & _retrievedVal ){
    if ( _pAIL != NULL ){
        _retrievedVal = _pAIL->miData;
        SNPtr save = _pAIL;
        delete [] _pAIL;        
        _pAIL = save->mpNext;
        return true;
    }
    return false;
}


bool Data::popBack( SNPtr & _pAIL, int& _retrievedVal ){
    if ( _pAIL == NULL ) return false;

    SNPtr save = _pAIL; // Salva endereço do head.
    SNPtr antepenult; // Salva endereço do antepenúltimo elemento.

    while ( _pAIL->mpNext != NULL ){
        antepenult = _pAIL;
        _pAIL = _pAIL->mpNext;
    }

    _retrievedVal = _pAIL->miData;

    delete [] _pAIL;

    antepenult->mpNext = NULL; // Antepenúltimo se torna o último.
    _pAIL = save; // Head volta à posição de origem.

    return true;
}


SNPtr Data::find( SNPtr _pAIL, int _targetVal ){
    while ( _pAIL != NULL and _pAIL->mpNext != NULL ){
        if ( _targetVal == _pAIL->mpNext->miData )
            return _pAIL;
        _pAIL = _pAIL->mpNext;
    }
    return NULL;
}


bool Data::insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal ){
    if ( _pAnte == NULL ){ // sem elementos na stack
        return pushFront( _pAIL, _newVal );
    }
    else{
        SNPtr save = _pAIL;
        while( _pAIL != _pAnte and _pAIL != NULL ){ // procura por elemento determinado
            _pAIL = _pAIL->mpNext;
        }
        if ( _pAIL == _pAnte ){
            pushFront( _pAIL->mpNext, _newVal );
        }
        _pAIL = save;
        if ( _pAIL == NULL ) return false;
        return true;
    }
}


bool Data::remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal ){
    if( _pAIL == NULL ) return false; // stack vazia

    if ( _pAnte == NULL ){ // retirar o primeiro elemento
            _retrievedVal = _pAIL->miData;
            SNPtr save = _pAIL;
            
            delete [] _pAIL;        
            _pAIL = save->mpNext;

            return true;
    }
    else { // retirar elemento em um lugar determinado da stack
        SNPtr save1 = _pAIL;
        while( _pAIL != _pAnte and _pAIL != NULL ){ // procura por elemento determinado
            _pAIL = _pAIL->mpNext;
        }

        // saída do while: _pAIL == _pAnte ou _pAIL == NULL

        if ( _pAIL == _pAnte ){ // elemento existe na stack
            _pAIL = _pAIL->mpNext; // _pAIL é o elemento que será deletado e _pAnte o anterior
            _pAnte->mpNext = _pAIL->mpNext;

            _retrievedVal = _pAIL->miData;
            delete [] _pAIL;           
        }
        _pAIL = save1;
        if ( _pAIL == NULL ) return false; // elemento não existe na stack
        return true;
    }
}