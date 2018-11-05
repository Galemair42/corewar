.name    "corrup_wall"
.comment "Wai"

ld %178520071,	r2			# 0A A4 00 07
ld %117440512,	r3			# 07 00 00 00
ld %117440513,	r4			# 07 00 00 01
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
sti r1, %:sec_back_wall, %1
fork %:sec_back_wall

back_wall:
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
fork %:sec_forward_wall
sti r1, %:sec_forward_wall, %1

forward_wall:
live %42
st r2, 200
st r3, 198
st r4, 193
st r1, 192

zjmp %:forward_wall

sec_forward_wall:
live%42
st r2, 210
st r3, 220
st r4, 230
st r1, 240

zjmp %:sec_forward_wall

end:
