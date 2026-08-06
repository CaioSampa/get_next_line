/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casampai <casampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:04:11 by casampai          #+#    #+#             */
/*   Updated: 2026/08/06 17:16:07 by casampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>   // Required for open() and flags like O_WRONLY
#include <unistd.h>  // Required for write() and close()
#include <string.h>  // Required for strlen()

int main() {

    int fd = open("text.txt", O_RDONLY);

    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }
    char    buff[100];
    int i ;
    int bytes_read;

    buff[99] = '\0';
    // variavel static para qual linha estamos
    // buffer com malloc para alocação dinamica
    // 
    
    

  

    close(fd);
    
    return 0;
}


char *get_next_line(int fd)
{
    
}

// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//     int fd = open("arquivo.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Erro ao abrir o arquivo");
//         return 1;
//     }

//     char buffer;
//     char linha[256];
//     int i = 0;
//     ssize_t bytes_lidos;

//     // Lê byte a byte até o fim do arquivo
//     while ((bytes_lidos = read(fd, &buffer, 1)) > 0) {
//         if (i < sizeof(linha) - 1) {
//             linha[i++] = buffer;
//         }

//         // Se encontrou o fim da linha
//         if (buffer == '\n') {
//             linha[i] = '\0'; // Finaliza a string
//             printf("Linha: %s", linha);
//             i = 0; // Reseta o índice para a próxima linha
//         }
//     }

//     // Trata a última linha caso não termine com \n
//     if (i > 0) {
//         linha[i] = '\0';
//         printf("Linha: %s\n", linha);
//     }

//     close(fd);
//     return 0;
// }
