/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

/**
 *
 * @author Willian
 */
public class StringDinamica {

    node head;

    static class node {

        char elemento;
        node proximo;
        node anterior;

        node(char elem) {
            elemento = elem;
            proximo = null;
        }
    }

    /**
     *
     * @param list
     * @param data
     * @return
     */
    public static StringDinamica insert(StringDinamica list, char data) {
        // Create a new node with given data
        node new_node = new node(data);

        // If the Linked List is empty,
        // then make the new node as head
        if (list.head == null) {
            list.head = new_node;
        } else {
            // Else traverse till the last node
            // and insert the new_node there
            node last = list.head;
            while (last.proximo != null) {
                last = last.proximo;
            }

            // Insert the new_node at last node
            last.proximo = new_node;
        }

        // Return the list by head
        return list;
    }

    /**
     *
     * @param list
     */
    public static String getString(StringDinamica list) {
        node currnode = list.head;

        String dados = "";

        // Traverse through the LinkedList
        while (currnode != null) {
            // Print the data at current node
            dados += currnode.elemento;

            // Go to proximo node
            currnode = currnode.proximo;
        }
        return dados;
    }
}
