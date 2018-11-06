.name    "corrup_wall"
.comment "Wai"

ld %42991616,	r2			# 02 90 00 00
ld %1,			r3			# 00 00 00 01
ld %167770880,	r4			# 09 FF FB 00
ld %0, r16
sti r1, %:debut, %1
sti r1, %:back_wall, %1
sti r1, %:prep_forward_wall, %1
sti r1, %:prep_back_wall, %1

debut:
live %42
fork %:prep_forward_wall

prep_back_wall:
live %42
fork %:sec_back_wall
sti r1, %:sec_back_wall, %1

back_wall:
live %42

st r2, -403
st r3, -405
st r1, -406
st r4, -407

st r2, -396
st r3, -398
st r1, -399
st r4, -400

st r2, -376
st r3, -378
st r1, -379
st r4, -380

st r2, -369
st r3, -371
st r1, -372
st r4, -373

zjmp %:back_wall

sec_back_wall:
live %42

st r2, -353
st r3, -355
st r1, -356
st r4, -357

st r2, -346
st r3, -348
st r1, -349
st r4, -350

st r2, -326
st r3, -328
st r1, -329
st r4, -330

st r2, -319
st r3, -321
st r1, -322
st r4, -323

zjmp %:sec_back_wall

prep_forward_wall:
live %42
fork %:sec_forward_wall
sti r1, %:sec_forward_wall, %1

forward_wall:
live %42

st r2, 378
st r3, 376
st r1, 375
st r4, 374

st r2, 385
st r3, 383
st r1, 382
st r4, 381

st r2, 408
st r3, 406
st r1, 405
st r4, 404

st r2, 415
st r3, 413
st r1, 412
st r4, 411

zjmp %:forward_wall

sec_forward_wall:

live%42

st r2, 150
st r3, 148
st r1, 147
st r4, 146

st r2, 157
st r3, 155
st r1, 154
st r4, 153

st r2, 180
st r3, 178
st r1, 177
st r4, 176

st r2, 187
st r3, 185
st r1, 184
st r4, 183

zjmp %:sec_forward_wall

end:
