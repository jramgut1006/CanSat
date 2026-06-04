#include <SPI.h>
#include <LoRa.h>

const int csPin = 18;
const int resetPin = 14;
const int irqPin = 26;
int frequency = 868E6;

// 11799870112109616910400765089876640788887
// 1799,87 11,2 0961,69 040,0765 898,7664 7888,87
// 11799,87 011,2 10961,69 1040,0765 0898,7664 07888,87
// +1799,87 -11,2 +0961,69 +040,0765 -898,7664 -7888,87

String Signo(String signo) {
  if (signo.equals("1")) {
      return "+";
  }
  else if (signo.equals("0")) {
      return "-";
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(frequency)) {
    Serial.println("Error al iniciar LoRa");
    while (1);
  }
  Serial.println("Receptor LoRa iniciado");

}

void loop() {
  int tamaño = LoRa.parsePacket();

  if (tamaño) {
    String valorRecibido = "";
    while (LoRa.available()) {
    valorRecibido += (char)LoRa.read();
    }

    Serial.print("Raw packet: ");
    Serial.println(valorRecibido);
    
    Serial.println("::::::::::::::::::::::::::::::::::::::::");

    String h = String(valorRecibido).substring(0, 8);
    String provisional_signo_h = String(valorRecibido).substring(0, 1);
    String signo_h = Signo(provisional_signo_h);

    String tm = String(valorRecibido).substring(7, 12);
    String provisional_signo_tm = String(valorRecibido).substring(7, 8);
    String signo_tm = Signo(provisional_signo_tm);

    String p = String(valorRecibido).substring(11, 19);
    String provisional_signo_p = String(valorRecibido).substring(11, 12);
    String signo_p = Signo(provisional_signo_p);    

    String lt = String(valorRecibido).substring(18, 28);
    String provisional_signo_lt = String(valorRecibido).substring(18, 19);
    String signo_lt = Signo(provisional_signo_lt);

    String ln = String(valorRecibido).substring(27, 37);
    String provisional_signo_ln = String(valorRecibido).substring(27, 28);
    String signo_ln = Signo(provisional_signo_ln);

    String tp = String(valorRecibido).substring(36, 44);
    String provisional_signo_tp = String(valorRecibido).substring(36, 37);
    String signo_tp = Signo(provisional_signo_tp);

    String acx = String(valorRecibido).substring(43, 50);
    String provisional_signo_acx = String(valorRecibido).substring(43, 44);
    String signo_acx = Signo(provisional_signo_acx);

    String acy = String(valorRecibido).substring(49, 56);
    String provisional_signo_acy = String(valorRecibido).substring(49, 50);
    String signo_acy = Signo(provisional_signo_acy);

    String acz = String(valorRecibido).substring(55, 62);
    String provisional_signo_acz = String(valorRecibido).substring(55, 56);
    String signo_acz = Signo(provisional_signo_acz);


    String gx = String(valorRecibido).substring(61, 68);
    String provisional_signo_gx = String(valorRecibido).substring(61, 62);
    String signo_gx = Signo(provisional_signo_gx);

    String gy = String(valorRecibido).substring(67, 74);
    String provisional_signo_gy = String(valorRecibido).substring(67, 68);
    String signo_gy = Signo(provisional_signo_gy);

    String gz = String(valorRecibido).substring(73, 80);
    String provisional_signo_gz = String(valorRecibido).substring(73, 74);
    String signo_gz = Signo(provisional_signo_gz);


    Serial.print("Altura: ");
    Serial.print(signo_h);
    String Sutoringu_H = h.substring(1, 5)+"."+h.substring(5, 7);
    Serial.println(Sutoringu_H);
    String FullH = signo_h + Sutoringu_H;

    Serial.print("Temperatura: ");
    Serial.print(signo_tm);
    String Sutoringu_TM = tm.substring(1, 3)+"."+tm.substring(3, 4);
    Serial.println(Sutoringu_TM);
    String FullTM = signo_tm + Sutoringu_TM;

    Serial.print("Presión: ");
    Serial.print(signo_p);
    String Sutoringu_P = p.substring(1, 5)+"."+p.substring(5, 7);
    Serial.println(Sutoringu_P);
    String FullP = signo_p + Sutoringu_P;

    Serial.print("Latitud: ");
    Serial.print(signo_lt);
    String Sutoringu_LT = lt.substring(1, 3)+"."+lt.substring(3, 9);
    Serial.println(Sutoringu_LT);
    String FullLT = signo_lt + Sutoringu_LT;

    Serial.print("Longitud: ");
    Serial.print(signo_ln);
    String Sutoringu_LN = ln.substring(1, 3)+"."+ln.substring(3, 9);
    Serial.println(Sutoringu_LN);
    String FullLN = signo_ln + Sutoringu_LN;

    Serial.print("Tiempo: ");
    Serial.print(signo_tp);
    String Sutoringu_TP = tp.substring(1, 5)+"."+tp.substring(5, 7);
    Serial.println(Sutoringu_TP);
    String FullTP = signo_tp + Sutoringu_TP;

    Serial.print("Aceleración X: ");
    Serial.print(signo_acx);
    String Sutoringu_ACX = acx.substring(1, 3)+"."+acx.substring(3, 7);
    Serial.println(Sutoringu_ACX);
    String FullACX = signo_acx + Sutoringu_ACX;

    Serial.print("Aceleración Y: ");
    Serial.print(signo_acy);
    String Sutoringu_ACY = acy.substring(1, 3)+"."+acy.substring(3, 7);
    Serial.println(Sutoringu_ACY);
    String FullACY = signo_acy + Sutoringu_ACY;

    Serial.print("Aceleración Z: ");
    Serial.print(signo_acz);
    String Sutoringu_ACZ = acz.substring(1, 3)+"."+acz.substring(3, 7);
    Serial.println(Sutoringu_ACZ);
    String FullACZ = signo_acz + Sutoringu_ACZ;

    Serial.print("Giroscopio X: ");
    Serial.print(signo_gx);
    String Sutoringu_GX = gx.substring(1, 3)+"."+gx.substring(3, 7);
    Serial.println(Sutoringu_GX);
    String FullGX = signo_gx + Sutoringu_GX;

    Serial.print("Giroscopio Y: ");
    Serial.print(signo_gy);
    String Sutoringu_GY = gy.substring(1, 3)+"."+gy.substring(3, 7);
    Serial.println(Sutoringu_GY);
    String FullGY = signo_gy + Sutoringu_GY;

    Serial.print("Giroscopio Z: ");
    Serial.print(signo_gz);
    String Sutoringu_GZ = gz.substring(1, 3)+"."+gz.substring(3, 7);
    Serial.println(Sutoringu_GZ);
    String FullGZ = signo_gz + Sutoringu_GZ;

    delay(100);
  }
}
