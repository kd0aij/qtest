__author__ = 'markw'

import numpy as np
import quaternion as quat

maxerror = 0

# run from astart to aend in astep degree increments
astart = np.deg2rad(-90)
aend = np.deg2rad(90)
astep = np.deg2rad(.001)

axis = np.array([1,1,0], dtype='double')
axis /= np.linalg.norm(axis)

# keep track of maximum step size in quantized rotation angle
maxstep = 0
maxstep_angle = 0

# init lastaq to the quantized angle
qq = quat.from_rotation_vector(astart * axis)
lastaq = np.dot(quat.as_rotation_vector(qq), axis)

aqlist = []

for angle in np.arange(astart, aend, astep):
    # construct double-precision quaternion representing rotation about Z by angle
    q = quat.from_rotation_vector(angle * axis)

    # quantize elements to float16
    for i in range(0,4):
        qq.components[i] = q.components[i].astype('float16')

    # normalize quaternion with quantized elements
    qq = qq.normalized()

    # calculate the quantized rotation angle and quantization error
    qangle = np.dot(quat.as_rotation_vector(qq), axis)
    error = qangle - angle
    if (abs(error) > maxerror): maxerror = abs(error)

    if (qangle != lastaq):
        aqlist.append([angle, qangle, error])
        # print('angle: %06.3f, quantized angle: %06.3f, error: %6.3f degrees' %
        #       (np.rad2deg(angle), np.rad2deg(qangle), np.rad2deg(error)))

        # update max quantized step size
        astep = abs(qangle - lastaq)
        lastaq = qangle
        if (astep > maxstep):
            maxstep = astep
            maxstep_angle = angle

print('maxerror: %f, maxstep: %f, maxstep_angle: %f' %
      (np.rad2deg(maxerror), np.rad2deg(maxstep), np.rad2deg(maxstep_angle)))

with open('float16_angles.csv', 'w') as outfile:
    outfile.write('angle,qangle,error\n')
    for i in range(0, len(aqlist)):
        outfile.write('%07.3f, %07.3f, %09.2e\n' %
              (np.rad2deg(aqlist[i][0]), np.rad2deg(aqlist[i][1]), np.rad2deg(aqlist[i][2])))
