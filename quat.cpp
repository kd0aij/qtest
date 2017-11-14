#include <QCoreApplication>
#include <QDebug>
#include <QQuaternion>
int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    
    qDebug() << "Hello World";
    float q1 = 1;
    float q2 = 0;
    float q3 = 0;
    float q4 = 0;
    QQuaternion quat(q1, q2, q3, q4);
    qDebug() << "quat: " << quat;
    
    QVector3D euler = quat.toEulerAngles();
    qDebug() << "identity euler: " << euler;
    
    float angle = 135;
    QVector3D axis(1,0,0);
    
    quat = QQuaternion::fromAxisAndAngle(axis, angle);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "axis: " << axis << " angle: " << angle << " euler: " << euler;
    qDebug() << "roll: " << euler.z() << ", pitch: " << euler.x() << " yaw: " << euler.y();
    
    angle = 90;
    quat = QQuaternion::fromAxisAndAngle(axis, angle);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "axis: " << axis << " angle: " << angle << " euler: " << euler;
    qDebug() << "roll: " << euler.z() << ", pitch: " << euler.x() << " yaw: " << euler.y();
    
    angle = 45;
    quat = QQuaternion::fromAxisAndAngle(axis, angle);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "axis: " << axis << " angle: " << angle << " euler: " << euler;
    qDebug() << "roll: " << euler.z() << ", pitch: " << euler.x() << " yaw: " << euler.y();
    
    QMatrix3x3 rot = quat.toRotationMatrix();
    qDebug() << "rotation matrix: " << rot;
    
    quat *= QQuaternion::fromAxisAndAngle(1, 0, 0, 10);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "10 deg X from right: euler: " << euler;

    quat *= QQuaternion::fromAxisAndAngle(0, 0, 1, 10);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "10 deg Z from right: euler: " << euler;

    quat *= QQuaternion::fromAxisAndAngle(1, 0, 0, 10);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "10 deg X from right: euler: " << euler;

    quat *= QQuaternion::fromAxisAndAngle(0, 0, 1, 10);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "10 deg Z from right: euler: " << euler;

    quat *= QQuaternion::fromAxisAndAngle(1, 0, 0, 10);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "10 deg X from right: euler: " << euler;

    quat *= QQuaternion::fromAxisAndAngle(0, 0, 1, 10);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "10 deg Z from right: euler: " << euler;

    quat *= QQuaternion::fromAxisAndAngle(1, 0, 0, 10);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "10 deg X from right: euler: " << euler;

    quat *= QQuaternion::fromAxisAndAngle(0, 0, 1, 10);
    qDebug() << "quat: " << quat;
    euler = quat.toEulerAngles();
    qDebug() << "10 deg Z from right: euler: " << euler;

//    return a.exec();
}
