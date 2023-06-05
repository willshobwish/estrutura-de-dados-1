/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

import model.StringDinamica;

/**
 *
 * @author Willian
 */
public class Controller {

//Padrao MVC, instanciacao de um unico controlador para todo o sistema, isso impede a instanciacao de outros controladores
    private static final Controller controller = new Controller();
//O controlador possui o objeto string dinamica instanciado
    private static StringDinamica stringDinamica = new StringDinamica();

    private Controller() {
    }

    /**
     * Instanciacao de apenas um controlador do modelo MVC
     *
     * @return a instancia unica do controlador
     */
    public static Controller getInstance() {
        return controller;
    }

    /**
     * Converte uma string em uma estrutura de dados de string dinamica
     *
     * @param entrada um objeto do tipo string para ser convertido na estrutura
     * de dado string dinamica
     * @param espaco booleano para verificar a adicao de espaco entre as
     * insercoes
     * @param quebraDeLinha booleano para verificar a adicao de quebra de linha
     * entre as insercoes
     */
    public void converterString(String entrada, boolean espaco, boolean quebraDeLinha) {
        char[] caracteres = entrada.toCharArray();
//Converte o objeto string para um vetor de caracteres
//O for percorre o vetor de char, previamente convertido do objeto string e insere na estrutura de dado "string dinamica"
        for (int i = 0; i < caracteres.length; i++) {
//            O vetor de caracteres eh processado por esse for, atribuindo na estrutura de dados "string dinamica"
            stringDinamica = stringDinamica.insert(stringDinamica, caracteres[i]);
        }
//       Caso seja necessario adicionar espaco entre as insercoes
        if (espaco) {
            stringDinamica = stringDinamica.insert(stringDinamica, ' ');
        }
//        Caso seja necessario adicionar quebra de linha entre as insercoes
        if (quebraDeLinha) {
            stringDinamica = stringDinamica.insert(stringDinamica, '\n');
        }
    }

    /**
     * Faz com que forme uma string a partir da estrutura de dados "string
     * dinamica"
     *
     * @return retorna uma string com os caracteres alocados na estrutura de
     * dados "string dinamica"
     */
    public String imprime() {
        return stringDinamica.getString(stringDinamica);
    }
}
