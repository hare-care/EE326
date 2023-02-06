/*
 * wifi.h
 *
 * Created: 2/1/2023 2:49:33 PM
 *  Author: hbajr
 */ 


#ifndef WIFI_H_
#define WIFI_H_
#include <asf.h>

// SPI definitions
#define SPI_CHIP_SEL 0
#define SPI_CHIP_PCS ((~(1u<<(chip_sel_id)))&0xF)
#define SPI_CLK_POLARITY 0
#define SPI_CLK_PHASE 0

#define NB_STATUS_CMD   20

#define SLAVE_STATE_IDLE           0
#define SLAVE_STATE_TEST           1
#define SLAVE_STATE_DATA           2
#define SLAVE_STATE_STATUS_ENTRY   3
#define SLAVE_STATE_STATUS         4
#define SLAVE_STATE_END            5

#define RC_SYN       0x55AA55AA


// SPI variables
struct status_block_t {
	/** Number of data blocks. */
	uint32_t ul_total_block_number;
	/** Number of SPI commands (including data blocks). */
	uint32_t ul_total_command_number;
	/** Command list. */
	uint32_t ul_cmd_list[NB_STATUS_CMD];
};

static struct status_block_t gs_spi_status;
static uint32_t gs_ul_spi_state;
static uint32_t gs_ul_spi_cmd;

static uint8_t *gs_puc_transfer_buffer;
static uint32_t gs_ul_transfer_index;
static uint32_t gs_ul_transfer_length;



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