class sumo_bot {
  private:
    //constantes definidas para los seguidores de linea
    const int sLnDer = 1;
    const int sLnIzq = 2;
    const int sLnCenter = 3;

    //constantes definidas para los sensores de aproximación
    const int sAprxDer = 4;
    const int sAprxIzq = 5;
    const int sAprxCenter = 6;
    const int sAprxAtrs = 7;

    //constante definidas para  el manejo de los motores
    const int mtrDerF = 8;
    const int mtrIzqF = 9;
    const int mtrDerA = 10;
    const int mtrIzqA = 11;

    //structura para manejar todos los datos de los sensores
    struct container{
      int sgLnDer;
      int sgLnIzq;
      int sgLnCenter;

      int snAprxIzq;
      int snAprxDer;
      int snAprxCenter;
      int snAprxAtrs;
    };

    //definición de banderas de estado
    int bSn = 0;
    int bSa = 0;

  public:
    sumo_bot() {
      pinMode(sLnDer,INPUT);
      pinMode(sLnIzq,INPUT);
      pinMode(sLnCenter,INPUT);
      
      pinMode(sAprxDer,INPUT);
      pinMode(sAprxIzq,INPUT);
      pinMode(sAprxCenter,INPUT);
      pinMode(sAprxAtrs,INPUT);

      pinMode(mtrDerF,OUTPUT);
      pinMode(mtrIzqF,OUTPUT);
      pinMode(mtrDerA,OUTPUT);
      pinMode(mtrIzqA,OUTPUT);
      
    }

    struct container getLectura(){
      struct container obj;
      obj.sgLnDer = digitalRead(sLnDer);
      obj.sgLnIzq = digitalRead(sLnDer);
      obj.sgLnCenter = digitalRead(sLnDer);

      obj.snAprxDer = digitalRead(sAprxDer);
      obj.snAprxIzq = digitalRead(sAprxIzq);
      obj.snAprxCenter = digitalRead(sAprxCenter);
      obj.snAprxAtrs = digitalRead(sAprxAtrs);
      
      return obj;
    }
    
    void moveFr(int vel){
      analogWrite(mtrDerF,vel);
      analogWrite(mtrIzqF,vel);
    }
    
    void moveAt(int vel){
      analogWrite(mtrDerA,vel);
      analogWrite(mtrIzqA,vel);
    }


};


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
