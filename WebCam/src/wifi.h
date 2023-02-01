/*
 * wifi.h
 *
 * Created: 2/1/2023 2:49:33 PM
 *  Author: hbajr
 */ 


#ifndef WIFI_H_
#define WIFI_H_
#include <asf.h>

void wifi_usart_handler(void);
void process_incoming_byte_wifi(uint8_t in_byte);
void wifi_command_repsonse_handler(uint32_t ul_id, uint32_t ul_mask);
void process_data_wifi(void);
void wifi_web_setup_handler(uint32_t ul_id, uint32_t ul_mask);
void wifi_spi_handler(void);
void configure_usart_wifi(void);
void configure_wifi_comm_pin(void);
void configure_wifi_provision_pin(void);
void configure_spi(void);
void spi_peripheral_initialize(void);
void prepare_spi_transfer(void);
void write_wifi_command(char* comm, uint8_t cnt);
void write_image_to_web(void);






#endif /* WIFI_H_ */