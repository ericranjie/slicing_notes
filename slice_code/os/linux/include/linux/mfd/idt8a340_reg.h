/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Based on 5.2.0, Family Programming Guide (Sept 30, 2020)
 *
 * Copyright (C) 2021 Integrated Device Technology, Inc., a Renesas Company.
 */
#ifndef HAVE_IDT8A340_REG
#define HAVE_IDT8A340_REG

#define PAGE_ADDR_BASE                    0x0000
#define PAGE_ADDR                         0x00fc

#define HW_REVISION                       0x8180
#define REV_ID                            0x007a

#define HW_DPLL_0                         (0x8a00)
#define HW_DPLL_1                         (0x8b00)
#define HW_DPLL_2                         (0x8c00)
#define HW_DPLL_3                         (0x8d00)
#define HW_DPLL_4                         (0x8e00)
#define HW_DPLL_5                         (0x8f00)
#define HW_DPLL_6                         (0x9000)
#define HW_DPLL_7                         (0x9100)

#define HW_DPLL_TOD_SW_TRIG_ADDR__0       (0x080)
#define HW_DPLL_TOD_CTRL_1                (0x089)
#define HW_DPLL_TOD_CTRL_2                (0x08A)
#define HW_DPLL_TOD_OVR__0                (0x098)
#define HW_DPLL_TOD_OUT_0__0              (0x0B0)

#define HW_Q0_Q1_CH_SYNC_CTRL_0           (0xa740)
#define HW_Q0_Q1_CH_SYNC_CTRL_1           (0xa741)
#define HW_Q2_Q3_CH_SYNC_CTRL_0           (0xa742)
#define HW_Q2_Q3_CH_SYNC_CTRL_1           (0xa743)
#define HW_Q4_Q5_CH_SYNC_CTRL_0           (0xa744)
#define HW_Q4_Q5_CH_SYNC_CTRL_1           (0xa745)
#define HW_Q6_Q7_CH_SYNC_CTRL_0           (0xa746)
#define HW_Q6_Q7_CH_SYNC_CTRL_1           (0xa747)
#define HW_Q8_CH_SYNC_CTRL_0              (0xa748)
#define HW_Q8_CH_SYNC_CTRL_1              (0xa749)
#define HW_Q9_CH_SYNC_CTRL_0              (0xa74a)
#define HW_Q9_CH_SYNC_CTRL_1              (0xa74b)
#define HW_Q10_CH_SYNC_CTRL_0             (0xa74c)
#define HW_Q10_CH_SYNC_CTRL_1             (0xa74d)
#define HW_Q11_CH_SYNC_CTRL_0             (0xa74e)
#define HW_Q11_CH_SYNC_CTRL_1             (0xa74f)

#define SYNC_SOURCE_DPLL0_TOD_PPS	0x14
#define SYNC_SOURCE_DPLL1_TOD_PPS	0x15
#define SYNC_SOURCE_DPLL2_TOD_PPS	0x16
#define SYNC_SOURCE_DPLL3_TOD_PPS	0x17

#define SYNCTRL1_MASTER_SYNC_RST	BIT(7)
#define SYNCTRL1_MASTER_SYNC_TRIG	BIT(5)
#define SYNCTRL1_TOD_SYNC_TRIG		BIT(4)
#define SYNCTRL1_FBDIV_FRAME_SYNC_TRIG	BIT(3)
#define SYNCTRL1_FBDIV_SYNC_TRIG	BIT(2)
#define SYNCTRL1_Q1_DIV_SYNC_TRIG	BIT(1)
#define SYNCTRL1_Q0_DIV_SYNC_TRIG	BIT(0)

#define HW_Q8_CTRL_SPARE  (0xa7d4)
#define HW_Q11_CTRL_SPARE (0xa7ec)

/*
 * Select FOD5 as sync_trigger for Q8 divider.
 * Transition from logic zero to one
 * sets trigger to sync Q8 divider.
 *
 * Unused when FOD4 is driving Q8 divider (normal operation).
 */
#define Q9_TO_Q8_SYNC_TRIG  BIT(1)

/*
 * Enable FOD5 as driver for clock and sync for Q8 divider.
 * Enable fanout buffer for FOD5.
 *
 * Unused when FOD4 is driving Q8 divider (normal operation).
 */
#define Q9_TO_Q8_FANOUT_AND_CLOCK_SYNC_ENABLE_MASK  (BIT(0) | BIT(2))

/*
 * Select FOD6 as sync_trigger for Q11 divider.
 * Transition from logic zero to one
 * sets trigger to sync Q11 divider.
 *
 * Unused when FOD7 is driving Q11 divider (normal operation).
 */
#define Q10_TO_Q11_SYNC_TRIG  BIT(1)

/*
 * Enable FOD6 as driver for clock and sync for Q11 divider.
 * Enable fanout buffer for FOD6.
 *
 * Unused when FOD7 is driving Q11 divider (normal operation).
 */
#define Q10_TO_Q11_FANOUT_AND_CLOCK_SYNC_ENABLE_MASK  (BIT(0) | BIT(2))

#define RESET_CTRL                        0xc000
#define SM_RESET                          0x0012
#define SM_RESET_V520                     0x0013
#define SM_RESET_CMD                      0x5A

#define GENERAL_STATUS                    0xc014
#define BOOT_STATUS                       0x0000
#define HW_REV_ID                         0x000A
#define BOND_ID                           0x000B
#define HW_CSR_ID                         0x000C
#define HW_IRQ_ID                         0x000E
#define MAJ_REL                           0x0010
#define MIN_REL                           0x0011
#define HOTFIX_REL                        0x0012
#define PIPELINE_ID                       0x0014
#define BUILD_ID                          0x0018
#define JTAG_DEVICE_ID                    0x001c
#define PRODUCT_ID                        0x001e
#define OTP_SCSR_CONFIG_SELECT            0x0022

#define STATUS                            0xc03c
#define DPLL0_STATUS			  0x0018
#define DPLL1_STATUS			  0x0019
#define DPLL2_STATUS			  0x001a
#define DPLL3_STATUS			  0x001b
#define DPLL4_STATUS			  0x001c
#define DPLL5_STATUS			  0x001d
#define DPLL6_STATUS			  0x001e
#define DPLL7_STATUS			  0x001f
#define DPLL_SYS_STATUS                   0x0020
#define DPLL_SYS_APLL_STATUS              0x0021
#define DPLL0_FILTER_STATUS               0x0044
#define DPLL1_FILTER_STATUS               0x004c
#define DPLL2_FILTER_STATUS               0x0054
#define DPLL3_FILTER_STATUS               0x005c
#define DPLL4_FILTER_STATUS               0x0064
#define DPLL5_FILTER_STATUS               0x006c
#define DPLL6_FILTER_STATUS               0x0074
#define DPLL7_FILTER_STATUS               0x007c
#define DPLLSYS_FILTER_STATUS             0x0084
#define USER_GPIO0_TO_7_STATUS            0x008a
#define USER_GPIO8_TO_15_STATUS           0x008b

#define GPIO_USER_CONTROL                 0xc160
#define GPIO0_TO_7_OUT                    0x0000
#define GPIO8_TO_15_OUT                   0x0001
#define GPIO0_TO_7_OUT_V520               0x0002
#define GPIO8_TO_15_OUT_V520              0x0003

#define STICKY_STATUS_CLEAR               0xc164

#define GPIO_TOD_NOTIFICATION_CLEAR       0xc16c

#define ALERT_CFG                         0xc188

#define SYS_DPLL_XO                       0xc194

#define SYS_APLL                          0xc19c

#define INPUT_0                           0xc1b0
#define INPUT_1                           0xc1c0
#define INPUT_2                           0xc1d0
#define INPUT_3                           0xc200
#define INPUT_4                           0xc210
#define INPUT_5                           0xc220
#define INPUT_6                           0xc230
#define INPUT_7                           0xc240
#define INPUT_8                           0xc250
#define INPUT_9                           0xc260
#define INPUT_10                          0xc280
#define INPUT_11                          0xc290
#define INPUT_12                          0xc2a0
#define INPUT_13                          0xc2b0
#define INPUT_14                          0xc2c0
#define INPUT_15                          0xc2d0

#define REF_MON_0                         0xc2e0
#define REF_MON_1                         0xc2ec
#define REF_MON_2                         0xc300
#define REF_MON_3                         0xc30c
#define REF_MON_4                         0xc318
#define REF_MON_5                         0xc324
#define REF_MON_6                         0xc330
#define REF_MON_7                         0xc33c
#define REF_MON_8                         0xc348
#define REF_MON_9                         0xc354
#define REF_MON_10                        0xc360
#define REF_MON_11                        0xc36c
#define REF_MON_12                        0xc380
#define REF_MON_13                        0xc38c
#define REF_MON_14                        0xc398
#define REF_MON_15                        0xc3a4

#define DPLL_0                            0xc3b0
#define DPLL_CTRL_REG_0                   0x0002
#define DPLL_CTRL_REG_1                   0x0003
#define DPLL_CTRL_REG_2                   0x0004
#define DPLL_TOD_SYNC_CFG                 0x0031
#define DPLL_COMBO_SLAVE_CFG_0            0x0032
#define DPLL_COMBO_SLAVE_CFG_1            0x0033
#define DPLL_SLAVE_REF_CFG                0x0034
#define DPLL_REF_MODE                     0x0035
#define DPLL_PHASE_MEASUREMENT_CFG        0x0036
#define DPLL_MODE                         0x0037
#define DPLL_MODE_V520                    0x003B
#define DPLL_1                            0xc400
#define DPLL_2                            0xc438
#define DPLL_2_V520                       0xc43c
#define DPLL_3                            0xc480
#define DPLL_4                            0xc4b8
#define DPLL_4_V520                       0xc4bc
#define DPLL_5                            0xc500
#define DPLL_6                            0xc538
#define DPLL_6_V520                       0xc53c
#define DPLL_7                            0xc580
#define SYS_DPLL                          0xc5b8
#define SYS_DPLL_V520                     0xc5bc

#define DPLL_CTRL_0                       0xc600
#define DPLL_CTRL_DPLL_MANU_REF_CFG       0x0001
#define DPLL_CTRL_DPLL_FOD_FREQ           0x001c
#define DPLL_CTRL_COMBO_MASTER_CFG        0x003a
#define DPLL_CTRL_1                       0xc63c
#define DPLL_CTRL_2                       0xc680
#define DPLL_CTRL_3                       0xc6bc
#define DPLL_CTRL_4                       0xc700
#define DPLL_CTRL_5                       0xc73c
#define DPLL_CTRL_6                       0xc780
#define DPLL_CTRL_7                       0xc7bc
#define SYS_DPLL_CTRL                     0xc800

#define DPLL_PHASE_0                      0xc818
/* Signed 42-bit FFO in units of 2^(-53) */
#define DPLL_WR_PHASE                     0x0000
#define DPLL_PHASE_1                      0xc81c
#define DPLL_PHASE_2                      0xc820
#define DPLL_PHASE_3                      0xc824
#define DPLL_PHASE_4                      0xc828
#define DPLL_PHASE_5                      0xc82c
#define DPLL_PHASE_6                      0xc830
#define DPLL_PHASE_7                      0xc834

#define DPLL_FREQ_0                       0xc838
/* Signed 42-bit FFO in units of 2^(-53) */
#define DPLL_WR_FREQ                      0x0000
#define DPLL_FREQ_1                       0xc840
#define DPLL_FREQ_2                       0xc848
#define DPLL_FREQ_3                       0xc850
#define DPLL_FREQ_4                       0xc858
#define DPLL_FREQ_5                       0xc860
#define DPLL_FREQ_6                       0xc868
#define DPLL_FREQ_7                       0xc870

#define DPLL_PHASE_PULL_IN_0              0xc880
#define PULL_IN_OFFSET                    0x0000 /* Signed 32 bit */
#define PULL_IN_SLOPE_LIMIT               0x0004 /* Unsigned 24 bit */
#define PULL_IN_CTRL                      0x0007
#define DPLL_PHASE_PULL_IN_1              0xc888
#define DPLL_PHASE_PULL_IN_2              0xc890
#define DPLL_PHASE_PULL_IN_3              0xc898
#define DPLL_PHASE_PULL_IN_4              0xc8a0
#define DPLL_PHASE_PULL_IN_5              0xc8a8
#define DPLL_PHASE_PULL_IN_6              0xc8b0
#define DPLL_PHASE_PULL_IN_7              0xc8b8

#define GPIO_CFG                          0xc8c0
#define GPIO_CFG_GBL                      0x0000
#define GPIO_0                            0xc8c2
#define GPIO_DCO_INC_DEC                  0x0000
#define GPIO_OUT_CTRL_0                   0x0001
#define GPIO_OUT_CTRL_1                   0x0002
#define GPIO_TOD_TRIG                     0x0003
#define GPIO_DPLL_INDICATOR               0x0004
#define GPIO_LOS_INDICATOR                0x0005
#define GPIO_REF_INPUT_DSQ_0              0x0006
#define GPIO_REF_INPUT_DSQ_1              0x0007
#define GPIO_REF_INPUT_DSQ_2              0x0008
#define GPIO_REF_INPUT_DSQ_3              0x0009
#define GPIO_MAN_CLK_SEL_0                0x000a
#define GPIO_MAN_CLK_SEL_1                0x000b
#define GPIO_MAN_CLK_SEL_2                0x000c
#define GPIO_SLAVE                        0x000d
#define GPIO_ALERT_OUT_CFG                0x000e
#define GPIO_TOD_NOTIFICATION_CFG         0x000f
#define GPIO_CTRL                         0x0010
#define GPIO_CTRL_V520                    0x0011
#define GPIO_1                            0xc8d4
#define GPIO_2                            0xc8e6
#define GPIO_3                            0xc900
#define GPIO_4                            0xc912
#define GPIO_5                            0xc924
#define GPIO_6                            0xc936
#define GPIO_7                            0xc948
#define GPIO_8                            0xc95a
#define GPIO_9                            0xc980
#define GPIO_10                           0xc992
#define GPIO_11                           0xc9a4
#define GPIO_12                           0xc9b6
#define GPIO_13                           0xc9c8
#define GPIO_14                           0xc9da
#define GPIO_15                           0xca00

#define OUT_DIV_MUX                       0xca12
#define OUTPUT_0                          0xca14
#define OUTPUT_0_V520                     0xca20
/* FOD frequency output divider value */
#define OUT_DIV                           0x0000
#define OUT_DUTY_CYCLE_HIGH               0x0004
#define OUT_CTRL_0                        0x0008
#define OUT_CTRL_1                        0x0009
/* Phase adjustment in FOD cycles */
#define OUT_PHASE_ADJ                     0x000c
#define OUTPUT_1                          0xca24
#define OUTPUT_1_V520                     0xca30
#define OUTPUT_2                          0xca34
#define OUTPUT_2_V520                     0xca40
#define OUTPUT_3                          0xca44
#define OUTPUT_3_V520                     0xca50
#define OUTPUT_4                          0xca54
#define OUTPUT_4_V520                     0xca60
#define OUTPUT_5                          0xca64
#define OUTPUT_5_V520                     0xca80
#define OUTPUT_6                          0xca80
#define OUTPUT_6_V520                     0xca90
#define OUTPUT_7                          0xca90
#define OUTPUT_7_V520                     0xcaa0
#define OUTPUT_8                          0xcaa0
#define OUTPUT_8_V520                     0xcab0
#define OUTPUT_9                          0xcab0
#define OUTPUT_9_V520                     0xcac0
#define OUTPUT_10                         0xcac0
#define OUTPUT_10_V520                     0xcad0
#define OUTPUT_11                         0xcad0
#define OUTPUT_11_V520                    0xcae0

#define SERIAL                            0xcae0
#define SERIAL_V520                       0xcaf0

#define PWM_ENCODER_0                     0xcb00
#define PWM_ENCODER_1                     0xcb08
#define PWM_ENCODER_2                     0xcb10
#define PWM_ENCODER_3                     0xcb18
#define PWM_ENCODER_4                     0xcb20
#define PWM_ENCODER_5                     0xcb28
#define PWM_ENCODER_6                     0xcb30
#define PWM_ENCODER_7                     0xcb38
#define PWM_DECODER_0                     0xcb40
#define PWM_DECODER_1                     0xcb48
#define PWM_DECODER_1_V520                0xcb4a
#define PWM_DECODER_2                     0xcb50
#define PWM_DECODER_2_V520                0xcb54
#define PWM_DECODER_3                     0xcb58
#define PWM_DECODER_3_V520                0xcb5e
#define PWM_DECODER_4                     0xcb60
#define PWM_DECODER_4_V520                0xcb68
#define PWM_DECODER_5                     0xcb68
#define PWM_DECODER_5_V520                0xcb80
#define PWM_DECODER_6                     0xcb70
#define PWM_DECODER_6_V520                0xcb8a
#define PWM_DECODER_7                     0xcb80
#define PWM_DECODER_7_V520                0xcb94
#define PWM_DECODER_8                     0xcb88
#define PWM_DECODER_8_V520                0xcb9e
#define PWM_DECODER_9                     0xcb90
#define PWM_DECODER_9_V520                0xcba8
#define PWM_DECODER_10                    0xcb98
#define PWM_DECODER_10_V520               0xcbb2
#define PWM_DECODER_11                    0xcba0
#define PWM_DECODER_11_V520               0xcbbc
#define PWM_DECODER_12                    0xcba8
#define PWM_DECODER_12_V520               0xcbc6
#define PWM_DECODER_13                    0xcbb0
#define PWM_DECODER_13_V520               0xcbd0
#define PWM_DECODER_14                    0xcbb8
#define PWM_DECODER_14_V520               0xcbda
#define PWM_DECODER_15                    0xcbc0
#define PWM_DECODER_15_V520               0xcbe4
#define PWM_USER_DATA                     0xcbc8
#define PWM_USER_DATA_V520                0xcbf0

#define TOD_0                             0xcbcc
#define TOD_0_V520                        0xcc00
/* Enable TOD counter, output channel sync and even-PPS mode */
#define TOD_CFG                           0x0000
#define TOD_CFG_V520                      0x0001
#define TOD_1                             0xcbce
#define TOD_1_V520                        0xcc02
#define TOD_2                             0xcbd0
#define TOD_2_V520                        0xcc04
#define TOD_3                             0xcbd2
#define TOD_3_V520                        0xcc06

#define TOD_WRITE_0                       0xcc00
#define TOD_WRITE_0_V520                  0xcc10
/* 8-bit subns, 32-bit ns, 48-bit seconds */
#define TOD_WRITE                         0x0000
/* Counter increments after TOD write is completed */
#define TOD_WRITE_COUNTER                 0x000c
/* TOD write trigger configuration */
#define TOD_WRITE_SELECT_CFG_0            0x000d
/* TOD write trigger selection */
#define TOD_WRITE_CMD                     0x000f
#define TOD_WRITE_1                       0xcc10
#define TOD_WRITE_1_V520                  0xcc20
#define TOD_WRITE_2                       0xcc20
#define TOD_WRITE_2_V520                  0xcc30
#define TOD_WRITE_3                       0xcc30
#define TOD_WRITE_3_V520                  0xcc40

#define TOD_READ_PRIMARY_0                0xcc40
#define TOD_READ_PRIMARY_0_V520           0xcc50
/* 8-bit subns, 32-bit ns, 48-bit seconds */
#define TOD_READ_PRIMARY_BASE             0x0000
/* Counter increments after TOD write is completed */
#define TOD_READ_PRIMARY_COUNTER          0x000b
/* Read trigger configuration */
#define TOD_READ_PRIMARY_SEL_CFG_0        0x000c
/* Read trigger selection */
#define TOD_READ_PRIMARY_CMD              0x000e
#define TOD_READ_PRIMARY_CMD_V520         0x000f
#define TOD_READ_PRIMARY_1                0xcc50
#define TOD_READ_PRIMARY_1_V520           0xcc60
#define TOD_READ_PRIMARY_2                0xcc60
#define TOD_READ_PRIMARY_2_V520           0xcc80
#define TOD_READ_PRIMARY_3                0xcc80
#define TOD_READ_PRIMARY_3_V520           0xcc90

#define TOD_READ_SECONDARY_0              0xcc90
#define TOD_READ_SECONDARY_0_V520         0xcca0
/* 8-bit subns, 32-bit ns, 48-bit seconds */
#define TOD_READ_SECONDARY_BASE           0x0000
/* Counter increments after TOD write is completed */
#define TOD_READ_SECONDARY_COUNTER        0x000b
/* Read trigger configuration */
#define TOD_READ_SECONDARY_SEL_CFG_0      0x000c
/* Read trigger selection */
#define TOD_READ_SECONDARY_CMD            0x000e
#define TOD_READ_SECONDARY_CMD_V520       0x000f

#define TOD_READ_SECONDARY_1              0xcca0
#define TOD_READ_SECONDARY_1_V520         0xccb0
#define TOD_READ_SECONDARY_2              0xccb0
#define TOD_READ_SECONDARY_2_V520         0xccc0
#define TOD_READ_SECONDARY_3              0xccc0
#define TOD_READ_SECONDARY_3_V520         0xccd0

#define OUTPUT_TDC_CFG                    0xccd0
#define OUTPUT_TDC_CFG_V520               0xcce0
#define OUTPUT_TDC_0                      0xcd00
#define OUTPUT_TDC_1                      0xcd08
#define OUTPUT_TDC_2                      0xcd10
#define OUTPUT_TDC_3                      0xcd18
#define INPUT_TDC                         0xcd20

#define SCRATCH                           0xcf50
#define SCRATCH_V520                      0xcf4c

#define EEPROM                            0xcf68
#define EEPROM_V520                       0xcf64

#define OTP                               0xcf70

#define BYTE                              0xcf80

/* Bit definitions for the MAJ_REL register */
#define MAJOR_SHIFT                       (1)
#define MAJOR_MASK                        (0x7f)
#define PR_BUILD                          BIT(0)

/* Bit definitions for the USER_GPIO0_TO_7_STATUS register */
#define GPIO0_LEVEL                       BIT(0)
#define GPIO1_LEVEL                       BIT(1)
#define GPIO2_LEVEL                       BIT(2)
#define GPIO3_LEVEL                       BIT(3)
#define GPIO4_LEVEL                       BIT(4)
#define GPIO5_LEVEL                       BIT(5)
#define GPIO6_LEVEL                       BIT(6)
#define GPIO7_LEVEL                       BIT(7)

/* Bit definitions for the USER_GPIO8_TO_15_STATUS register */
#define GPIO8_LEVEL                       BIT(0)
#define GPIO9_LEVEL                       BIT(1)
#define GPIO10_LEVEL                      BIT(2)
#define GPIO11_LEVEL                      BIT(3)
#define GPIO12_LEVEL                      BIT(4)
#define GPIO13_LEVEL                      BIT(5)
#define GPIO14_LEVEL                      BIT(6)
#define GPIO15_LEVEL                      BIT(7)

/* Bit definitions for the GPIO0_TO_7_OUT register */
#define GPIO0_DRIVE_LEVEL                 BIT(0)
#define GPIO1_DRIVE_LEVEL                 BIT(1)
#define GPIO2_DRIVE_LEVEL                 BIT(2)
#define GPIO3_DRIVE_LEVEL                 BIT(3)
#define GPIO4_DRIVE_LEVEL                 BIT(4)
#define GPIO5_DRIVE_LEVEL                 BIT(5)
#define GPIO6_DRIVE_LEVEL                 BIT(6)
#define GPIO7_DRIVE_LEVEL                 BIT(7)

/* Bit definitions for the GPIO8_TO_15_OUT register */
#define GPIO8_DRIVE_LEVEL                 BIT(0)
#define GPIO9_DRIVE_LEVEL                 BIT(1)
#define GPIO10_DRIVE_LEVEL                BIT(2)
#define GPIO11_DRIVE_LEVEL                BIT(3)
#define GPIO12_DRIVE_LEVEL                BIT(4)
#define GPIO13_DRIVE_LEVEL                BIT(5)
#define GPIO14_DRIVE_LEVEL                BIT(6)
#define GPIO15_DRIVE_LEVEL                BIT(7)

/* Bit definitions for the DPLL_TOD_SYNC_CFG register */
#define TOD_SYNC_SOURCE_SHIFT             (1)
#define TOD_SYNC_SOURCE_MASK              (0x3)
#define TOD_SYNC_EN                       BIT(0)

/* Bit definitions for the DPLL_MODE register */
#define WRITE_TIMER_MODE                  BIT(6)
#define PLL_MODE_SHIFT                    (3)
#define PLL_MODE_MASK                     (0x7)
#define STATE_MODE_SHIFT                  (0)
#define STATE_MODE_MASK                   (0x7)

/* Bit definitions for the DPLL_MANU_REF_CFG register */
#define MANUAL_REFERENCE_SHIFT            (0)
#define MANUAL_REFERENCE_MASK             (0x1f)

/* Bit definitions for the GPIO_CFG_GBL register */
#define SUPPLY_MODE_SHIFT                 (0)
#define SUPPLY_MODE_MASK                  (0x3)

/* Bit definitions for the GPIO_DCO_INC_DEC register */
#define INCDEC_DPLL_INDEX_SHIFT           (0)
#define INCDEC_DPLL_INDEX_MASK            (0x7)

/* Bit definitions for the GPIO_OUT_CTRL_0 register */
#define CTRL_OUT_0                        BIT(0)
#define CTRL_OUT_1                        BIT(1)
#define CTRL_OUT_2                        BIT(2)
#define CTRL_OUT_3                        BIT(3)
#define CTRL_OUT_4                        BIT(4)
#define CTRL_OUT_5                        BIT(5)
#define CTRL_OUT_6                        BIT(6)
#define CTRL_OUT_7                        BIT(7)

/* Bit definitions for the GPIO_OUT_CTRL_1 register */
#define CTRL_OUT_8                        BIT(0)
#define CTRL_OUT_9                        BIT(1)
#define CTRL_OUT_10                       BIT(2)
#define CTRL_OUT_11                       BIT(3)
#define CTRL_OUT_12                       BIT(4)
#define CTRL_OUT_13                       BIT(5)
#define CTRL_OUT_14                       BIT(6)
#define CTRL_OUT_15                       BIT(7)

/* Bit definitions for the GPIO_TOD_TRIG register */
#define TOD_TRIG_0                        BIT(0)
#define TOD_TRIG_1                        BIT(1)
#define TOD_TRIG_2                        BIT(2)
#define TOD_TRIG_3                        BIT(3)

/* Bit definitions for the GPIO_DPLL_INDICATOR register */
#define IND_DPLL_INDEX_SHIFT              (0)
#define IND_DPLL_INDEX_MASK               (0x7)

/* Bit definitions for the GPIO_LOS_INDICATOR register */
#define REFMON_INDEX_SHIFT                (0)
#define REFMON_INDEX_MASK                 (0xf)
/* Active level of LOS indicator, 0=low 1=high */
#define ACTIVE_LEVEL                      BIT(4)

/* Bit definitions for the GPIO_REF_INPUT_DSQ_0 register */
#define DSQ_INP_0                         BIT(0)
#define DSQ_INP_1                         BIT(1)
#define DSQ_INP_2                         BIT(2)
#define DSQ_INP_3                         BIT(3)
#define DSQ_INP_4                         BIT(4)
#define DSQ_INP_5                         BIT(5)
#define DSQ_INP_6                         BIT(6)
#define DSQ_INP_7                         BIT(7)

/* Bit definitions for the GPIO_REF_INPUT_DSQ_1 register */
#define DSQ_INP_8                         BIT(0)
#define DSQ_INP_9                         BIT(1)
#define DSQ_INP_10                        BIT(2)
#define DSQ_INP_11                        BIT(3)
#define DSQ_INP_12                        BIT(4)
#define DSQ_INP_13                        BIT(5)
#define DSQ_INP_14                        BIT(6)
#define DSQ_INP_15                        BIT(7)

/* Bit definitions for the GPIO_REF_INPUT_DSQ_2 register */
#define DSQ_DPLL_0                        BIT(0)
#define DSQ_DPLL_1                        BIT(1)
#define DSQ_DPLL_2                        BIT(2)
#define DSQ_DPLL_3                        BIT(3)
#define DSQ_DPLL_4                        BIT(4)
#define DSQ_DPLL_5                        BIT(5)
#define DSQ_DPLL_6                        BIT(6)
#define DSQ_DPLL_7                        BIT(7)

/* Bit definitions for the GPIO_REF_INPUT_DSQ_3 register */
#define DSQ_DPLL_SYS                      BIT(0)
#define GPIO_DSQ_LEVEL                    BIT(1)

/* Bit definitions for the GPIO_TOD_NOTIFICATION_CFG register */
#define DPLL_TOD_SHIFT                    (0)
#define DPLL_TOD_MASK                     (0x3)
#define TOD_READ_SECONDARY                BIT(2)
#define GPIO_ASSERT_LEVEL                 BIT(3)

/* Bit definitions for the GPIO_CTRL register */
#define GPIO_FUNCTION_EN                  BIT(0)
#define GPIO_CMOS_OD_MODE                 BIT(1)
#define GPIO_CONTROL_DIR                  BIT(2)
#define GPIO_PU_PD_MODE                   BIT(3)
#define GPIO_FUNCTION_SHIFT               (4)
#define GPIO_FUNCTION_MASK                (0xf)

/* Bit definitions for the OUT_CTRL_1 register */
#define OUT_SYNC_DISABLE                  BIT(7)
#define SQUELCH_VALUE                     BIT(6)
#define SQUELCH_DISABLE                   BIT(5)
#define PAD_VDDO_SHIFT                    (2)
#define PAD_VDDO_MASK                     (0x7)
#define PAD_CMOSDRV_SHIFT                 (0)
#define PAD_CMOSDRV_MASK                  (0x3)

/* Bit definitions for the TOD_CFG register */
#define TOD_EVEN_PPS_MODE                 BIT(2)
#define TOD_OUT_SYNC_ENABLE               BIT(1)
#define TOD_ENABLE                        BIT(0)

/* Bit definitions for the TOD_WRITE_SELECT_CFG_0 register */
#define WR_PWM_DECODER_INDEX_SHIFT        (4)
#define WR_PWM_DECODER_INDEX_MASK         (0xf)
#define WR_REF_INDEX_SHIFT                (0)
#define WR_REF_INDEX_MASK                 (0xf)

/* Bit definitions for the TOD_WRITE_CMD register */
#define TOD_WRITE_SELECTION_SHIFT         (0)
#define TOD_WRITE_SELECTION_MASK          (0xf)
/* 4.8.7 */
#define TOD_WRITE_TYPE_SHIFT              (4)
#define TOD_WRITE_TYPE_MASK               (0x3)

/* Bit definitions for the TOD_READ_PRIMARY_SEL_CFG_0 register */
#define RD_PWM_DECODER_INDEX_SHIFT        (4)
#define RD_PWM_DECODER_INDEX_MASK         (0xf)
#define RD_REF_INDEX_SHIFT                (0)
#define RD_REF_INDEX_MASK                 (0xf)

/* Bit definitions for the TOD_READ_PRIMARY_CMD register */
#define TOD_READ_TRIGGER_MODE             BIT(4)
#define TOD_READ_TRIGGER_SHIFT            (0)
#define TOD_READ_TRIGGER_MASK             (0xf)

/* Bit definitions for the DPLL_CTRL_COMBO_MASTER_CFG register */
#define COMBO_MASTER_HOLD                 BIT(0)

/* Bit definitions for DPLL_SYS_STATUS register */
#define DPLL_SYS_STATE_MASK               (0xf)

/* Bit definitions for SYS_APLL_STATUS register */
#define SYS_APLL_LOSS_LOCK_LIVE_MASK       BIT(0)
#define SYS_APLL_LOSS_LOCK_LIVE_LOCKED     0
#define SYS_APLL_LOSS_LOCK_LIVE_UNLOCKED   1

/* Bit definitions for the DPLL0_STATUS register */
#define DPLL_STATE_MASK                   (0xf)
#define DPLL_STATE_SHIFT                  (0x0)

/* Values of DPLL_N.DPLL_MODE.PLL_MODE */
enum pll_mode {
	PLL_MODE_MIN = 0,
	PLL_MODE_PLL = PLL_MODE_MIN,
	PLL_MODE_WRITE_PHASE = 1,
	PLL_MODE_WRITE_FREQUENCY = 2,
	PLL_MODE_GPIO_INC_DEC = 3,
	PLL_MODE_SYNTHESIS = 4,
	PLL_MODE_PHASE_MEASUREMENT = 5,
	PLL_MODE_DISABLED = 6,
	PLL_MODE_MAX = PLL_MODE_DISABLED,
};

/* Values of DPLL_CTRL_n.DPLL_MANU_REF_CFG.MANUAL_REFERENCE */
enum manual_reference {
	MANU_REF_MIN = 0,
	MANU_REF_CLK0 = MANU_REF_MIN,
	MANU_REF_CLK1,
	MANU_REF_CLK2,
	MANU_REF_CLK3,
	MANU_REF_CLK4,
	MANU_REF_CLK5,
	MANU_REF_CLK6,
	MANU_REF_CLK7,
	MANU_REF_CLK8,
	MANU_REF_CLK9,
	MANU_REF_CLK10,
	MANU_REF_CLK11,
	MANU_REF_CLK12,
	MANU_REF_CLK13,
	MANU_REF_CLK14,
	MANU_REF_CLK15,
	MANU_REF_WRITE_PHASE,
	MANU_REF_WRITE_FREQUENCY,
	MANU_REF_XO_DPLL,
	MANU_REF_MAX = MANU_REF_XO_DPLL,
};

enum hw_tod_write_trig_sel {
	HW_TOD_WR_TRIG_SEL_MIN = 0,
	HW_TOD_WR_TRIG_SEL_MSB = HW_TOD_WR_TRIG_SEL_MIN,
	HW_TOD_WR_TRIG_SEL_RESERVED = 1,
	HW_TOD_WR_TRIG_SEL_TOD_PPS = 2,
	HW_TOD_WR_TRIG_SEL_IRIGB_PPS = 3,
	HW_TOD_WR_TRIG_SEL_PWM_PPS = 4,
	HW_TOD_WR_TRIG_SEL_GPIO = 5,
	HW_TOD_WR_TRIG_SEL_FOD_SYNC = 6,
	WR_TRIG_SEL_MAX = HW_TOD_WR_TRIG_SEL_FOD_SYNC,
};

enum scsr_read_trig_sel {
	/* CANCEL CURRENT TOD READ; MODULE BECOMES IDLE - NO TRIGGER OCCURS */
	SCSR_TOD_READ_TRIG_SEL_DISABLE = 0,
	/* TRIGGER IMMEDIATELY */
	SCSR_TOD_READ_TRIG_SEL_IMMEDIATE = 1,
	/* TRIGGER ON RISING EDGE OF INTERNAL TOD PPS SIGNAL */
	SCSR_TOD_READ_TRIG_SEL_TODPPS = 2,
	/* TRGGER ON RISING EDGE OF SELECTED REFERENCE INPUT */
	SCSR_TOD_READ_TRIG_SEL_REFCLK = 3,
	/* TRIGGER ON RISING EDGE OF SELECTED PWM DECODER 1PPS OUTPUT */
	SCSR_TOD_READ_TRIG_SEL_PWMPPS = 4,
	SCSR_TOD_READ_TRIG_SEL_RESERVED = 5,
	/* TRIGGER WHEN WRITE FREQUENCY EVENT OCCURS  */
	SCSR_TOD_READ_TRIG_SEL_WRITEFREQUENCYEVENT = 6,
	/* TRIGGER ON SELECTED GPIO */
	SCSR_TOD_READ_TRIG_SEL_GPIO = 7,
	SCSR_TOD_READ_TRIG_SEL_MAX = SCSR_TOD_READ_TRIG_SEL_GPIO,
};

/* Values STATUS.DPLL_SYS_STATUS.DPLL_SYS_STATE */
enum dpll_state {
	DPLL_STATE_MIN = 0,
	DPLL_STATE_FREERUN = DPLL_STATE_MIN,
	DPLL_STATE_LOCKACQ = 1,
	DPLL_STATE_LOCKREC = 2,
	DPLL_STATE_LOCKED = 3,
	DPLL_STATE_HOLDOVER = 4,
	DPLL_STATE_OPEN_LOOP = 5,
	DPLL_STATE_MAX = DPLL_STATE_OPEN_LOOP,
};

/* 4.8.7 only */
enum scsr_tod_write_trig_sel {
	SCSR_TOD_WR_TRIG_SEL_DISABLE = 0,
	SCSR_TOD_WR_TRIG_SEL_IMMEDIATE = 1,
	SCSR_TOD_WR_TRIG_SEL_REFCLK = 2,
	SCSR_TOD_WR_TRIG_SEL_PWMPPS = 3,
	SCSR_TOD_WR_TRIG_SEL_TODPPS = 4,
	SCSR_TOD_WR_TRIG_SEL_SYNCFOD = 5,
	SCSR_TOD_WR_TRIG_SEL_GPIO = 6,
	SCSR_TOD_WR_TRIG_SEL_MAX = SCSR_TOD_WR_TRIG_SEL_GPIO,
};

/* 4.8.7 only */
enum scsr_tod_write_type_sel {
	SCSR_TOD_WR_TYPE_SEL_ABSOLUTE = 0,
	SCSR_TOD_WR_TYPE_SEL_DELTA_PLUS = 1,
	SCSR_TOD_WR_TYPE_SEL_DELTA_MINUS = 2,
	SCSR_TOD_WR_TYPE_SEL_MAX = SCSR_TOD_WR_TYPE_SEL_DELTA_MINUS,
};
#endif
