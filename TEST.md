# Tests cases for rods_cached.c (Solves Rod Cutting Problem)

# Test Case 1: Program Accepts Valid Rod Lengths Only

### Description: 
A test to verify that the user must provide a valid file name

### Input: 
./rodslru bullshido.txt

./rodsfifo bullshido.txt

./rodslru cut_lengths_prices.txt

./rodsfifo cut_lengths_prices.txt


### Expected Output: 
Indicates that a file was not found and exits the program if an invalid file name is provided. 

### Actual Output

./rodslru bullshido.txt
File not found. (Exits)

./rodsfifo bullshido.txt
File not found. (Exits)

./rodslru cut_lengths_prices.txt
Program continues

./rodsfifo cut_lengths_prices.txt
Program continues


# Test Case 2: Program Accepts Valid Rod Lengths Only

### Description: 
A test to verify that the user must input a rod length greater than 0 with no additional characters

### Input: 
100a
-1 
a100
99

### Expected Output: 
Program rejects any input which is not a valid integer 

### Actual Output

Program commences with calculating cut list only when a valid length is entered

./rodslru cut_lengths_prices.txt
100a
Rod length must be a positive integer
-1
Invalid input. Enter a positive value.
a100
Rod length must be a positive integer
99
4 @ 22 = 200
Remainder = 11
Value = 200


# Test Case 3: Testing Various Cache Sizes for Eviction



### Description: Smallest LRU Cache Rod Length that resulted in Evictions

### 3.A LRU Evictions

### Input: 
189

### Output: 

1 Evictions

189
2 @ 17 = 60
7 @ 22 = 350
Remainder = 1
Value = 410
Cache Contents (Size: 100/100):
Entry 1: Key = 189, Value = 410, Last Access Time = 278
Entry 2: Key = 0, Value = 0, Last Access Time = 35
Entry 3: Key = 22, Value = 50, Last Access Time = 33
Entry 4: Key = 17, Value = 30, Last Access Time = 235
Entry 5: Key = 39, Value = 80, Last Access Time = 232
Entry 6: Key = 4, Value = 0, Last Access Time = 60
Entry 7: Key = 21, Value = 30, Last Access Time = 69
Entry 8: Key = 16, Value = 0, Last Access Time = 83
Entry 9: Key = 38, Value = 60, Last Access Time = 80
Entry 10: Key = 10, Value = 0, Last Access Time = 73
Entry 11: Key = 11, Value = 0, Last Access Time = 101
Entry 12: Key = 33, Value = 50, Last Access Time = 98
Entry 13: Key = 55, Value = 100, Last Access Time = 95
Entry 14: Key = 27, Value = 50, Last Access Time = 88
Entry 15: Key = 6, Value = 0, Last Access Time = 125
Entry 16: Key = 28, Value = 50, Last Access Time = 122
Entry 17: Key = 50, Value = 100, Last Access Time = 119
Entry 18: Key = 72, Value = 150, Last Access Time = 116
Entry 19: Key = 44, Value = 100, Last Access Time = 109
Entry 20: Key = 1, Value = 0, Last Access Time = 237
Entry 21: Key = 23, Value = 50, Last Access Time = 236
Entry 22: Key = 45, Value = 100, Last Access Time = 234
Entry 23: Key = 67, Value = 150, Last Access Time = 231
Entry 24: Key = 89, Value = 200, Last Access Time = 228
Entry 25: Key = 3, Value = 0, Last Access Time = 155
Entry 26: Key = 20, Value = 30, Last Access Time = 164
Entry 27: Key = 15, Value = 0, Last Access Time = 162
Entry 28: Key = 37, Value = 60, Last Access Time = 175
Entry 29: Key = 9, Value = 0, Last Access Time = 168
Entry 30: Key = 32, Value = 50, Last Access Time = 173
Entry 31: Key = 54, Value = 100, Last Access Time = 186
Entry 32: Key = 26, Value = 50, Last Access Time = 179
Entry 33: Key = 49, Value = 100, Last Access Time = 184
Entry 34: Key = 71, Value = 150, Last Access Time = 197
Entry 35: Key = 43, Value = 80, Last Access Time = 190
Entry 36: Key = 66, Value = 150, Last Access Time = 211
Entry 37: Key = 88, Value = 200, Last Access Time = 208
Entry 38: Key = 60, Value = 110, Last Access Time = 201
Entry 39: Key = 61, Value = 130, Last Access Time = 229
Entry 40: Key = 83, Value = 180, Last Access Time = 226
Entry 41: Key = 105, Value = 230, Last Access Time = 223
Entry 42: Key = 77, Value = 150, Last Access Time = 216
Entry 43: Key = 12, Value = 0, Last Access Time = 268
Entry 44: Key = 34, Value = 60, Last Access Time = 265
Entry 45: Key = 56, Value = 110, Last Access Time = 262
Entry 46: Key = 78, Value = 160, Last Access Time = 259
Entry 47: Key = 100, Value = 210, Last Access Time = 256
Entry 48: Key = 122, Value = 260, Last Access Time = 253
Entry 49: Key = 94, Value = 200, Last Access Time = 246
Entry 50: Key = 7, Value = 0, Last Access Time = 266
Entry 51: Key = 29, Value = 50, Last Access Time = 263
Entry 52: Key = 51, Value = 100, Last Access Time = 260
Entry 53: Key = 73, Value = 150, Last Access Time = 257
Entry 54: Key = 95, Value = 200, Last Access Time = 254
Entry 55: Key = 117, Value = 250, Last Access Time = 251
Entry 56: Key = 139, Value = 300, Last Access Time = 133
Entry 57: Key = 2, Value = 0, Last Access Time = 142
Entry 58: Key = 19, Value = 30, Last Access Time = 143
Entry 59: Key = 14, Value = 0, Last Access Time = 170
Entry 60: Key = 36, Value = 60, Last Access Time = 145
Entry 61: Key = 8, Value = 0, Last Access Time = 151
Entry 62: Key = 31, Value = 50, Last Access Time = 181
Entry 63: Key = 53, Value = 100, Last Access Time = 150
Entry 64: Key = 25, Value = 50, Last Access Time = 159
Entry 65: Key = 48, Value = 100, Last Access Time = 192
Entry 66: Key = 70, Value = 150, Last Access Time = 158
Entry 67: Key = 42, Value = 80, Last Access Time = 169
Entry 68: Key = 65, Value = 130, Last Access Time = 203
Entry 69: Key = 87, Value = 180, Last Access Time = 167
Entry 70: Key = 59, Value = 110, Last Access Time = 180
Entry 71: Key = 82, Value = 160, Last Access Time = 218
Entry 72: Key = 104, Value = 210, Last Access Time = 178
Entry 73: Key = 76, Value = 150, Last Access Time = 191
Entry 74: Key = 99, Value = 200, Last Access Time = 248
Entry 75: Key = 121, Value = 250, Last Access Time = 189
Entry 76: Key = 93, Value = 200, Last Access Time = 202
Entry 77: Key = 116, Value = 250, Last Access Time = 207
Entry 78: Key = 138, Value = 300, Last Access Time = 200
Entry 79: Key = 110, Value = 250, Last Access Time = 217
Entry 80: Key = 111, Value = 250, Last Access Time = 225
Entry 81: Key = 133, Value = 300, Last Access Time = 222
Entry 82: Key = 155, Value = 350, Last Access Time = 215
Entry 83: Key = 127, Value = 280, Last Access Time = 247
Entry 84: Key = 18, Value = 30, Last Access Time = 269
Entry 85: Key = 40, Value = 80, Last Access Time = 267
Entry 86: Key = 62, Value = 130, Last Access Time = 264
Entry 87: Key = 84, Value = 180, Last Access Time = 261
Entry 88: Key = 106, Value = 230, Last Access Time = 258
Entry 89: Key = 128, Value = 280, Last Access Time = 255
Entry 90: Key = 150, Value = 330, Last Access Time = 252
Entry 91: Key = 172, Value = 380, Last Access Time = 245
Entry 92: Key = 144, Value = 310, Last Access Time = 250
Entry 93: Key = 13, Value = 0, Last Access Time = 270
Entry 94: Key = 35, Value = 60, Last Access Time = 271
Entry 95: Key = 57, Value = 110, Last Access Time = 272
Entry 96: Key = 79, Value = 160, Last Access Time = 273
Entry 97: Key = 101, Value = 210, Last Access Time = 274
Entry 98: Key = 123, Value = 260, Last Access Time = 275
Entry 99: Key = 145, Value = 310, Last Access Time = 276
Entry 100: Key = 167, Value = 360, Last Access Time = 277
Evictions: 1

### Input: 

200

### Output:

12 Evictions 

200
9 @ 22 = 450
Remainder = 2
Value = 450
Cache Contents (Size: 100/100):
Entry 1: Key = 0, Value = 0, Last Access Time = 125
Entry 2: Key = 161, Value = 350, Last Access Time = 289
Entry 3: Key = 24, Value = 50, Last Access Time = 310
Entry 4: Key = 155, Value = 350, Last Access Time = 287
Entry 5: Key = 183, Value = 400, Last Access Time = 282
Entry 6: Key = 6, Value = 0, Last Access Time = 272
Entry 7: Key = 28, Value = 50, Last Access Time = 269
Entry 8: Key = 50, Value = 100, Last Access Time = 266
Entry 9: Key = 68, Value = 150, Last Access Time = 312
Entry 10: Key = 46, Value = 100, Last Access Time = 311
Entry 11: Key = 112, Value = 250, Last Access Time = 314
Entry 12: Key = 90, Value = 200, Last Access Time = 313
Entry 13: Key = 178, Value = 400, Last Access Time = 317
Entry 14: Key = 156, Value = 350, Last Access Time = 316
Entry 15: Key = 134, Value = 300, Last Access Time = 315
Entry 16: Key = 22, Value = 50, Last Access Time = 123
Entry 17: Key = 44, Value = 100, Last Access Time = 120
Entry 18: Key = 66, Value = 150, Last Access Time = 117
Entry 19: Key = 200, Value = 450, Last Access Time = 318
Entry 20: Key = 17, Value = 30, Last Access Time = 150
Entry 21: Key = 39, Value = 80, Last Access Time = 147
Entry 22: Key = 61, Value = 130, Last Access Time = 144
Entry 23: Key = 83, Value = 180, Last Access Time = 141
Entry 24: Key = 55, Value = 100, Last Access Time = 134
Entry 25: Key = 12, Value = 0, Last Access Time = 273
Entry 26: Key = 34, Value = 60, Last Access Time = 271
Entry 27: Key = 56, Value = 110, Last Access Time = 268
Entry 28: Key = 78, Value = 160, Last Access Time = 265
Entry 29: Key = 100, Value = 210, Last Access Time = 262
Entry 30: Key = 14, Value = 0, Last Access Time = 187
Entry 31: Key = 9, Value = 0, Last Access Time = 185
Entry 32: Key = 31, Value = 50, Last Access Time = 198
Entry 33: Key = 3, Value = 0, Last Access Time = 191
Entry 34: Key = 26, Value = 50, Last Access Time = 196
Entry 35: Key = 48, Value = 100, Last Access Time = 209
Entry 36: Key = 20, Value = 30, Last Access Time = 202
Entry 37: Key = 43, Value = 80, Last Access Time = 207
Entry 38: Key = 65, Value = 130, Last Access Time = 220
Entry 39: Key = 37, Value = 60, Last Access Time = 213
Entry 40: Key = 60, Value = 110, Last Access Time = 218
Entry 41: Key = 82, Value = 160, Last Access Time = 231
Entry 42: Key = 54, Value = 100, Last Access Time = 224
Entry 43: Key = 77, Value = 150, Last Access Time = 245
Entry 44: Key = 99, Value = 200, Last Access Time = 242
Entry 45: Key = 71, Value = 150, Last Access Time = 235
Entry 46: Key = 72, Value = 150, Last Access Time = 263
Entry 47: Key = 94, Value = 200, Last Access Time = 260
Entry 48: Key = 116, Value = 250, Last Access Time = 257
Entry 49: Key = 88, Value = 200, Last Access Time = 250
Entry 50: Key = 1, Value = 0, Last Access Time = 307
Entry 51: Key = 23, Value = 50, Last Access Time = 305
Entry 52: Key = 45, Value = 100, Last Access Time = 302
Entry 53: Key = 67, Value = 150, Last Access Time = 299
Entry 54: Key = 89, Value = 200, Last Access Time = 296
Entry 55: Key = 111, Value = 250, Last Access Time = 293
Entry 56: Key = 133, Value = 300, Last Access Time = 290
Entry 57: Key = 105, Value = 230, Last Access Time = 283
Entry 58: Key = 18, Value = 30, Last Access Time = 303
Entry 59: Key = 40, Value = 80, Last Access Time = 300
Entry 60: Key = 62, Value = 130, Last Access Time = 297
Entry 61: Key = 84, Value = 180, Last Access Time = 294
Entry 62: Key = 106, Value = 230, Last Access Time = 291
Entry 63: Key = 128, Value = 280, Last Access Time = 288
Entry 64: Key = 150, Value = 330, Last Access Time = 159
Entry 65: Key = 13, Value = 0, Last Access Time = 168
Entry 66: Key = 8, Value = 0, Last Access Time = 193
Entry 67: Key = 30, Value = 50, Last Access Time = 170
Entry 68: Key = 2, Value = 0, Last Access Time = 309
Entry 69: Key = 25, Value = 50, Last Access Time = 204
Entry 70: Key = 47, Value = 100, Last Access Time = 175
Entry 71: Key = 19, Value = 30, Last Access Time = 182
Entry 72: Key = 42, Value = 80, Last Access Time = 215
Entry 73: Key = 64, Value = 130, Last Access Time = 181
Entry 74: Key = 36, Value = 60, Last Access Time = 192
Entry 75: Key = 59, Value = 110, Last Access Time = 226
Entry 76: Key = 81, Value = 160, Last Access Time = 190
Entry 77: Key = 53, Value = 100, Last Access Time = 203
Entry 78: Key = 76, Value = 150, Last Access Time = 237
Entry 79: Key = 98, Value = 200, Last Access Time = 201
Entry 80: Key = 70, Value = 150, Last Access Time = 214
Entry 81: Key = 93, Value = 200, Last Access Time = 252
Entry 82: Key = 115, Value = 250, Last Access Time = 212
Entry 83: Key = 87, Value = 180, Last Access Time = 225
Entry 84: Key = 110, Value = 250, Last Access Time = 285
Entry 85: Key = 132, Value = 300, Last Access Time = 223
Entry 86: Key = 104, Value = 210, Last Access Time = 236
Entry 87: Key = 127, Value = 280, Last Access Time = 241
Entry 88: Key = 149, Value = 330, Last Access Time = 234
Entry 89: Key = 121, Value = 250, Last Access Time = 251
Entry 90: Key = 122, Value = 260, Last Access Time = 259
Entry 91: Key = 144, Value = 310, Last Access Time = 256
Entry 92: Key = 166, Value = 360, Last Access Time = 249
Entry 93: Key = 138, Value = 300, Last Access Time = 284
Entry 94: Key = 7, Value = 0, Last Access Time = 308
Entry 95: Key = 29, Value = 50, Last Access Time = 306
Entry 96: Key = 51, Value = 100, Last Access Time = 304
Entry 97: Key = 73, Value = 150, Last Access Time = 301
Entry 98: Key = 95, Value = 200, Last Access Time = 298
Entry 99: Key = 117, Value = 250, Last Access Time = 295
Entry 100: Key = 139, Value = 300, Last Access Time = 292
Evictions: 12


### 3.B FIFO Evictions

### Input: 

189 

### Output:

189 

1 Eviction

2 @ 17 = 60
7 @ 22 = 350
Remainder = 1
Value = 410
Cache Contents (Size: 100/100):
Key = 0, Value = 0
Key = 22, Value = 50
Key = 17, Value = 30
Key = 39, Value = 80
Key = 4, Value = 0
Key = 21, Value = 30
Key = 16, Value = 0
Key = 38, Value = 60
Key = 10, Value = 0
Key = 11, Value = 0
Key = 33, Value = 50
Key = 55, Value = 100
Key = 27, Value = 50
Key = 6, Value = 0
Key = 28, Value = 50
Key = 50, Value = 100
Key = 72, Value = 150
Key = 44, Value = 100
Key = 1, Value = 0
Key = 23, Value = 50
Key = 45, Value = 100
Key = 67, Value = 150
Key = 89, Value = 200
Key = 3, Value = 0
Key = 20, Value = 30
Key = 15, Value = 0
Key = 37, Value = 60
Key = 9, Value = 0
Key = 32, Value = 50
Key = 54, Value = 100
Key = 26, Value = 50
Key = 49, Value = 100
Key = 71, Value = 150
Key = 43, Value = 80
Key = 66, Value = 150
Key = 88, Value = 200
Key = 60, Value = 110
Key = 61, Value = 130
Key = 83, Value = 180
Key = 105, Value = 230
Key = 77, Value = 150
Key = 12, Value = 0
Key = 34, Value = 60
Key = 56, Value = 110
Key = 78, Value = 160
Key = 100, Value = 210
Key = 122, Value = 260
Key = 94, Value = 200
Key = 7, Value = 0
Key = 29, Value = 50
Key = 51, Value = 100
Key = 73, Value = 150
Key = 95, Value = 200
Key = 117, Value = 250
Key = 139, Value = 300
Key = 2, Value = 0
Key = 19, Value = 30
Key = 14, Value = 0
Key = 36, Value = 60
Key = 8, Value = 0
Key = 31, Value = 50
Key = 53, Value = 100
Key = 25, Value = 50
Key = 48, Value = 100
Key = 70, Value = 150
Key = 42, Value = 80
Key = 65, Value = 130
Key = 87, Value = 180
Key = 59, Value = 110
Key = 82, Value = 160
Key = 104, Value = 210
Key = 76, Value = 150
Key = 99, Value = 200
Key = 121, Value = 250
Key = 93, Value = 200
Key = 116, Value = 250
Key = 138, Value = 300
Key = 110, Value = 250
Key = 111, Value = 250
Key = 133, Value = 300
Key = 155, Value = 350
Key = 127, Value = 280
Key = 18, Value = 30
Key = 40, Value = 80
Key = 62, Value = 130
Key = 84, Value = 180
Key = 106, Value = 230
Key = 128, Value = 280
Key = 150, Value = 330
Key = 172, Value = 380
Key = 144, Value = 310
Key = 13, Value = 0
Key = 35, Value = 60
Key = 57, Value = 110
Key = 79, Value = 160
Key = 101, Value = 210
Key = 123, Value = 260
Key = 145, Value = 310
Key = 167, Value = 360
Key = 189, Value = 410
Evictions: 1

### Input 

200 

### Output 

12 Evictions 

200
9 @ 22 = 450
Remainder = 2
Value = 450
Cache Contents (Size: 100/100):
Key = 27, Value = 50
Key = 49, Value = 100
Key = 21, Value = 30
Key = 22, Value = 50
Key = 44, Value = 100
Key = 66, Value = 150
Key = 38, Value = 60
Key = 17, Value = 30
Key = 39, Value = 80
Key = 61, Value = 130
Key = 83, Value = 180
Key = 55, Value = 100
Key = 12, Value = 0
Key = 34, Value = 60
Key = 56, Value = 110
Key = 78, Value = 160
Key = 100, Value = 210
Key = 14, Value = 0
Key = 9, Value = 0
Key = 31, Value = 50
Key = 3, Value = 0
Key = 26, Value = 50
Key = 48, Value = 100
Key = 20, Value = 30
Key = 43, Value = 80
Key = 65, Value = 130
Key = 37, Value = 60
Key = 60, Value = 110
Key = 82, Value = 160
Key = 54, Value = 100
Key = 77, Value = 150
Key = 99, Value = 200
Key = 71, Value = 150
Key = 72, Value = 150
Key = 94, Value = 200
Key = 116, Value = 250
Key = 88, Value = 200
Key = 1, Value = 0
Key = 23, Value = 50
Key = 45, Value = 100
Key = 67, Value = 150
Key = 89, Value = 200
Key = 111, Value = 250
Key = 133, Value = 300
Key = 105, Value = 230
Key = 18, Value = 30
Key = 40, Value = 80
Key = 62, Value = 130
Key = 84, Value = 180
Key = 106, Value = 230
Key = 128, Value = 280
Key = 150, Value = 330
Key = 13, Value = 0
Key = 8, Value = 0
Key = 30, Value = 50
Key = 2, Value = 0
Key = 25, Value = 50
Key = 47, Value = 100
Key = 19, Value = 30
Key = 42, Value = 80
Key = 64, Value = 130
Key = 36, Value = 60
Key = 59, Value = 110
Key = 81, Value = 160
Key = 53, Value = 100
Key = 76, Value = 150
Key = 98, Value = 200
Key = 70, Value = 150
Key = 93, Value = 200
Key = 115, Value = 250
Key = 87, Value = 180
Key = 110, Value = 250
Key = 132, Value = 300
Key = 104, Value = 210
Key = 127, Value = 280
Key = 149, Value = 330
Key = 121, Value = 250
Key = 122, Value = 260
Key = 144, Value = 310
Key = 166, Value = 360
Key = 138, Value = 300
Key = 7, Value = 0
Key = 29, Value = 50
Key = 51, Value = 100
Key = 73, Value = 150
Key = 95, Value = 200
Key = 117, Value = 250
Key = 139, Value = 300
Key = 161, Value = 350
Key = 183, Value = 400
Key = 155, Value = 350
Key = 24, Value = 50
Key = 46, Value = 100
Key = 68, Value = 150
Key = 90, Value = 200
Key = 112, Value = 250
Key = 134, Value = 300
Key = 156, Value = 350
Key = 178, Value = 400
Key = 200, Value = 450
Evictions: 12


# Test Case 4: Testing Various Cache Sizes for Processing Speed 

# 4.0 NO Cache

### Description: 
Running the program with no cache

### Input 
./rods cut_lengths_prices.txt
100
200
500

### Expected Output: 
The greater the rod length, the longer it will take to process the problem. 
Will likely handle rod lengths up to 1000. 

### Actual Output: 
NO CACHE
Rod Length 100 - Solved instantly
Rod Length 200 - Slight Delay, but Solved
Rod Length 500 - Program Crashed  


# 4.A LRU and FIFO Cache Size: 100

### Description: 
LRU Cache Size 100
FIFO Cache Size 100

### Input: 
## LRU 100
Rod Length 100
Rod Length 500 
Rod Length 1000

## FIFO 100
Rod Length 100
Rod Length 500 
Rod Length 1000

### Expected Output: 
The greater the rod length, the longer it will take to process the problem

### Actual Output: 
LRU 
Rod Length 100 - Solved instantly
Rod Length 500 - Slight Delay, but Solved 
ROd Length 1000 - Program Crashed

FIFO 
Rod Length 100 - Solved instantly
Rod Length 500 - Slight Delay, but Solved 
ROd Length 1000 - Program Crashed

# 4.B LRU and FIFO Cache Size: 1000

### Description: 
LRU Cache Size 1000
FIFO Cache Size 1000

### Input: 
## LRU 
Rod Length 100
Rod Length 500 
Rod Length 1000
Rod Length 2000
Rod Length 5000
Rod Length 10000
Rod Length 15000
Rod Length 20000
Rod Length 25000
Rod Length 30000
Rod Length 50000
Rod Length 100000
Rod Length 200000
Rod Length 500000

## FIFO 
Rod Length 100
Rod Length 500 
Rod Length 1000
Rod Length 2000
Rod Length 5000
Rod Length 10000
Rod Length 15000
Rod Length 20000
Rod Length 25000
Rod Length 30000
Rod Length 50000
Rod Length 100000
Rod Length 200000
Rod Length 500000

### Expected Output: 
Program will handle larger numbers, but eventually crashed

### Actual Output: 
Program computed values nearly instantly, even up to 200000 (with very minor delay). Program terminated
at rod length 500000.