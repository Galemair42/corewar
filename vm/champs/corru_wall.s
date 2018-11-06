.name    "corrup_wall"
.comment "Wai"


zjmp %-5
ld %178520071,	r2			# 0A A4 00 07
ld %117440513,	r3			# 07 00 00 01
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

st r2, -500
st r3, -502
st r1, -503
st r4, -504
st r1, -370

st r2, -270
st r3, -272
st r4, -277
st r1, -278

st r2, -301
st r3, -303
st r4, -308
st r1, -309

st r2, -332
st r3, -334
st r4, -339
st r1, -340

st r2, -363
st r3, -365
st r4, -370
st r1, -371

st r2, -394
st r3, -396
st r4, -401
st r1, -402

zjmp %:back_wall

sec_back_wall:
live %42
st r2, -239
st r3, -241
st r4, -246
st r1, -247

st r2, -270
st r3, -272
st r4, -277
st r1, -278

st r2, -301
st r3, -303
st r4, -308
st r1, -309

st r2, -332
st r3, -334
st r4, -339
st r1, -340

st r2, -363
st r3, -365
st r4, -370
st r1, -371

st r2, -394
st r3, -396
st r4, -401
st r1, -402

zjmp %:sec_back_wall

prep_forward_wall:
live %42
fork %:sec_forward_wall
sti r1, %:sec_forward_wall, %1

forward_wall:
live %42

st r2, 413
st r3, 411
st r4, 406
st r1, 405

st r2, 404
st r3, 402
st r4, 397
st r1, 396

st r2, 395
st r3, 393
st r4, 388
st r1, 387

st r2, 386
st r3, 384
st r4, 379
st r1, 378

st r2, 377
st r3, 375
st r4, 370
st r1, 369

st r2, 368
st r3, 366
st r4, 361
st r1, 360

zjmp %:forward_wall

sec_forward_wall:

live%42

st r2, 157
st r3, 155
st r4, 150
st r1, 149

st r2, 148
st r3, 146
st r4, 141
st r1, 140

st r2, 139
st r3, 137
st r4, 133
st r1, 132

st r2, 131
st r3, 129
st r4, 124
st r1, 123

st r2, 122
st r3, 120
st r4, 115
st r1, 114

st r2, 113
st r3, 111
st r4, 106
st r1, 105

zjmp %:sec_forward_wall

end:
