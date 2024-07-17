#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stm32h7xx_hal.h"


extern FDCAN_HandleTypeDef hfdcan1; // Ensure this matches the declaration in your main file
extern "C" void Error_Handler(void);
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim5;
extern FDCAN_TxHeaderTypeDef TxHeader;
extern FDCAN_RxHeaderTypeDef RxHeader;
extern uint8_t TxData[4];
extern uint8_t RxData[4];




Model::Model()
{

}

void Model::tick()
{

}


void Model::RedSlider(int value)
{
    TxData[3] = static_cast<uint8_t>(value);
    TxHeader.Identifier = 0x114;
    TxHeader.DataLength = FDCAN_DLC_BYTES_1;
    HAL_FDCAN_AddMessageToTxBuffer(&hfdcan1, &TxHeader, &TxData[3], FDCAN_TX_BUFFER3);
    HAL_FDCAN_EnableTxBufferRequest(&hfdcan1, FDCAN_TX_BUFFER3);
    //HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_BUFFER3, &RxHeader, &RxData[3]);
}

void Model::GreenSlider(int value)
{
    TxData[2] = static_cast<uint8_t>(value);
    TxHeader.Identifier = 0x113;
    TxHeader.DataLength = FDCAN_DLC_BYTES_1;
    HAL_FDCAN_AddMessageToTxBuffer(&hfdcan1, &TxHeader, &TxData[2], FDCAN_TX_BUFFER2);
    HAL_FDCAN_EnableTxBufferRequest(&hfdcan1, FDCAN_TX_BUFFER2);
    //HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_BUFFER2, &RxHeader, &RxData[2]);
}

void Model::Blue(int value)
{
    TxData[0] = static_cast<uint8_t>(value);
    TxHeader.Identifier = 0x112;
    TxHeader.DataLength = FDCAN_DLC_BYTES_1;
    HAL_FDCAN_AddMessageToTxBuffer(&hfdcan1, &TxHeader, &TxData[0], FDCAN_TX_BUFFER1);
    HAL_FDCAN_EnableTxBufferRequest(&hfdcan1, FDCAN_TX_BUFFER1);
    //HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_BUFFER1, &RxHeader, &RxData[0]);
}

void Model::sendWhiteValue(int value)
{
    TxData[1] = static_cast<uint8_t>(value);
    TxHeader.Identifier = 0x111;
    TxHeader.DataLength = FDCAN_DLC_BYTES_1;
    HAL_FDCAN_AddMessageToTxBuffer(&hfdcan1, &TxHeader, &TxData[1], FDCAN_TX_BUFFER0);
    HAL_FDCAN_EnableTxBufferRequest(&hfdcan1, FDCAN_TX_BUFFER0);
   // HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_BUFFER0, &RxHeader, &RxData[1]);
}
