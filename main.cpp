/*

IMPORTANTE

Dale al play de arriba para ejecutar

este es un programa bastante simple, por lo que solo traduce ciertos
caracteres. podes traducir de la A a la Z, tanto en mayuscula como en
minuscula (las mayusculas se convierten en minusculas automaticamente) 
menos la ñ (se va a reemplazar por "ni") y tambien traduce espacios y 
numeros. no escribas puntos, comas guiones, signos de explamacion, etc
porque se va a buguear. solo eso.

Flareonz44 :)

*/
#include <iostream>
#include <string>
using namespace std;
const string spanishCharDictionary[] = {" ", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " "};
const string asbackCharDictionary[] = {" ", "-+++.", ",+++.", "+-++.", "--++.", ",-++.", "+,++.", "-,++.", ",,++.", "++-+.", "-+-+.", ",+-+.", "+--+.", "---+.", ",--+.", "+,-+.", "-,-+.", ",,-+.", "++,+.", "-+,+.", ",+,+.", "+-,+.", "--,+.", ",-,+.", "+,,+.", "-,,+.", ",,,+.", "+++-.", "-++-.", ",++-.", "+-+-.", "--+-.", ",-+-.", "+,+-.", "-,+-.", ",,+-.", "++--.", ".."};
string replaceAll(string str, const string from, const string to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
string translateToAsback14(string sText){
    for(auto& c : sText){
       c = tolower(c);
    }
    sText = replaceAll(sText, "ñ", "ni");
    for (int x = 0; x <= (sizeof(asbackCharDictionary)/sizeof(asbackCharDictionary[0])); x++){
        sText = replaceAll(sText, spanishCharDictionary[x], asbackCharDictionary[x]);
    }
    return sText;
}
string translateBackFromAsback14(string sText){
    for (int x = 0; x <= (sizeof(asbackCharDictionary)/sizeof(asbackCharDictionary[0])) -1; x++){
        sText = replaceAll(sText, asbackCharDictionary[x], spanishCharDictionary[x]);
    }
    return sText;
    return sText;
}
int main() {
    string optionTask;
    bool ok = false;
    string inText;
    cout << "Welcome to Asback 14 Languaje Tool!" << endl;
    cout << "Choose and option to continue:" << endl;
    cout << "   1 - Translate to Asback 14" << endl;
    cout << "   2 - De-translate from Asback 14" << endl;
    cout << "Choose 1 or 2: ";
    getline(cin, optionTask);
    while (!ok){
        if (optionTask == "1"){
            ok = true;
            break;
        }else if (optionTask == "2"){
            ok = true;
            break;
        }else{
            cout << "Please, choose 1 or 2: ";
            getline(cin, optionTask);
            ok = false;
        }
    }
    printf("\033c");
    if (optionTask == "1"){
        cout << "First enter a text to translate below:" << endl;
        getline(cin, inText);
        cout << "---> Input text:" << endl;
        cout << inText << endl;
        cout << "Translating..." << endl;
        inText = translateToAsback14(inText);
        cout << "---> Output Text:" << endl;
        cout << inText;
        return 0;
    }else if (optionTask == "2"){
        cout << "First enter a text to de-translate below:" << endl;
        getline(cin, inText);
        cout << "---> Input text:" << endl;
        cout << inText << endl;
        cout << "De-translating..." << endl;
        inText = translateBackFromAsback14(inText);
        cout << "---> Output Text:" << endl;
        cout << inText;
        return 0;
    }else{
        cout << endl << endl << "Something went wrong..." << endl << endl;
    }
}
