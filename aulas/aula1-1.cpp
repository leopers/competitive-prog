#include "stdc++.h"

using namespace std;

int getStartOfNameOnEnd(string& line){
    for(int i = line.size()-1; i >= 0; i--)
        if(line[i] == ' ')
            return i + 1;
    return -1;
}

int getEndOfNameOnBegin(string& line){ //passar por ref pra nn fazer copia,
// diminui o tempo para o caso de inputs grandes
    for(int i = 0; i < line.size(); i++)
        if(line[i] == ' ')
            return i;
    return -1;
}

int main()
{
    string line;
    // Esse loop é interrompido ao encontrar o
    // caractere EOF. No terminal, podemos simular
    // esse caractere utilizando o comando ctrl + D
    
    while (getline(cin, line))
    {
        string infoNumbers;
        string name;

        // nome no fim
        if(isdigit(line[0]))
        {
            int idx = getStartOfNameOnEnd(line);
            infoNumbers = line.substr(0, idx-1);
            name = line.substr(idx);
        }
        // nome começo
        else
        {
            int idx = getEndOfNameOnBegin(line);
            infoNumbers = line.substr(idx);
            name = line.substr(0, idx);
        }

        // A classe stringstream herda de iostream.
        // Como utilizamos o objeto numbersStream apenas para ler valores
        // formatados dele, poderiamos utilizar a classe istringstream
        // (um pouco mais restrita, visto que não contém métodos e operadores da classe ostream),
        // que herda de istream e funciona basicamente como o cin que conhecemos
        // (visto que o cin é objeto da classe istream, logo cin e objetos de
        // istringstream funcionam basicamente igual).
        // 
        // Para mais detalhes sobre isso, veja https://www.cplusplus.com/reference/iolibrary/
        //
        // Bizu pra quem não pegou:
        // i -> input
        // o -> output
        // io -> input e output
        // logo, objetos de que herdam de iostream (como os objetos da classe stringstream)
        // podem ser utilizados para input e output. Objetos da classe (ou subclasses de)
        // istream podem ser utilizados apenas para para input, e da classe (ou subclasses de)
        // ostream apenas para output.
        //
        // Dica: vejam todos os métodos que tem nas classes istream, ostream e nas classes
        // base delas (como ios e ios_base) para vocês entenderem o que é possível executar
 
        stringstream numbersStream(infoNumbers);
        double sum = 0;
        double number;
        int count = 0;
        while(numbersStream >> number)
        {
            sum += number;
            count++;
        }

        double mean = sum / count;
        // printando a média com precisão fixa
        // de duas casas decimais
        cout << fixed << setprecision(2) << name << " " << mean << endl;
        // Printando a média no piso inteiro em hexadecimal
        cout << hex << name << " " << (int)mean << endl;

        // Conseguimos utilizar as ferramentas de formatação
        // do "cout" (tecnicamente, as ferramentas da classe ostream
        // https://www.cplusplus.com/reference/ostream/ostream/ )
        // em um objeto da classe stringstream e depois passar
        // de volta pra um objeto string.
        stringstream formatedStreamOut;
        formatedStreamOut << hex << (int)mean;
        string ex;
        formatedStreamOut >> ex;
        for(auto c : ex)
            // O bug na aula foi causado devido ao fato da função
            // to upper retornar um inteiro ( https://www.cplusplus.com/reference/cctype/toupper/ )
            // Esse inteiro deve ser convertido para char para podermos
            // printar o caractere adequadamente.
            // Note também que como passamos a flag "hex" anteriormente para o cout,
            // foi printado '46' que é o valor hexadecimal do 'F' na tabela ascii
            cout << (char)toupper(c);
        cout << endl;
    }
}