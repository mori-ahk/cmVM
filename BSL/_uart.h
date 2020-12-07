//
// Created by Morteza Ahmadi on 2020-12-06.
//

#ifndef SRC__UART_H
#define SRC__UART_H

void uart_init(void);
void uart_TxChar(char);
char uart_RxChar(void);

#endif //SRC__UART_H
