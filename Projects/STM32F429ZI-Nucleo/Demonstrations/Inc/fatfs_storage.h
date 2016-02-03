/**
  ******************************************************************************
  * @file    fatfs_storage.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    13-November-2015
  * @brief   This file contains all the functions prototypes for the storage
  *          firmware driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FATFS_STORAGE_H
#define __FATFS_STORAGE_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
  
/* Header of a bitmap file */
#pragma pack(1) /* Mandatory to remove any padding */
typedef struct BmpHeader
{
  uint8_t  B;
  uint8_t  M;
  uint32_t fsize;
  uint16_t res1;
  uint16_t res2;
  uint32_t offset;
  uint32_t hsize;
  uint32_t w;
  uint32_t h;
  uint16_t planes;
  uint16_t bpp;
  uint32_t ctype;
  uint32_t dsize;
  uint32_t hppm;
  uint32_t vppm;
  uint32_t colorsused;
  uint32_t colorreq;
}BmpHeader;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint32_t Storage_OpenReadFile(uint8_t Xpoz, uint16_t Ypoz, const char *BmpName);
uint32_t Storage_CopyFile(const char *BmpName1, const char *BmpName2);
uint32_t Storage_GetDirectoryBitmapFiles(const char* DirName, char* Files[]);
uint32_t Storage_CheckBitmapFile(const char *BmpName, uint32_t *FileLen);
uint8_t  Buffercmp(uint8_t *pBuffer1, uint8_t *pBuffer2, uint16_t BufferLength);

#ifdef __cplusplus
}
#endif

#endif /* __FATFS_STORAGE_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
