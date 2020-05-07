import java.util.Scanner;

/**
 *
 * @author Alex Galhardo 
 * @where ICMC USP 2018
 */
public class Motorcycle {
    
    private int speed;
    private int gear;
    private int ID;
    public static int numberOfMotorcycles = 0;
    private int metros;
    private int posicao;
    
    Motorcycle(int speed, int gear){
        this.speed = speed;
        this.gear = gear;
        this.metros = 0;
        this.posicao = 0;
        this.ID = ++Motorcycle.numberOfMotorcycles;
    }
    
    Motorcycle(){
        this.speed = 0;
        this.gear = 1;
        this.metros = 0;
        this.posicao = 0;
        this.ID = ++Motorcycle.numberOfMotorcycles;
    }
    
    public int getGear(){
        return this.gear;
    }
    
    public void gearUp(){
        this.gear++;
        if(this.gear > 2){
            this.speed = 40;
        }
        else if(this.gear>3){
            this.speed = 80;
        }
        else if(this.gear>4){
            this.speed = 120;
        }
        else{
            this.speed = 160;
        }
    }
    
    public int getSpeed(){
        return this.speed;
    }
    
    public void applyBreaks(){
        this.speed = 0;
    }
    
    public int getID(){
        return this.ID;
    }
    
    public void setSpeed(int speed){
        this.speed = speed;
        if(this.getSpeed() >= 40 && this.getSpeed() < 80){
            this.gear = 2;
        }
        else if(this.getSpeed() >= 80 && this.getSpeed() < 120){
            this.gear = 3;
        }
        else if(this.getSpeed() >= 120 && this.getSpeed() < 160){
            this.gear = 3;
        }
        else{
            this.gear = 4;
        }
    }
    
    public void setGear(int gear){
        this.gear = gear;
        if(this.gear == 2){
            this.speed = 40;
        }
        else if(this.getGear() == 3){
            this.speed = 80;
        }
        else if(this.gear == 4){
            this.speed = 120;
        }
        else{
            this.speed = 160;
        }
    }
    
    public void addSpeed(int speedToAdd){
        this.speed += speedToAdd;
        this.metros += this.speed;
        
        if(this.getSpeed() < 40){
            this.gear = 1;
        }
        else if(this.getSpeed() >= 40 && this.getSpeed() < 80){
            this.gear = 2;
        }
        else if(this.getSpeed() >= 80 && this.getSpeed() < 120){
            this.gear = 3;
        }
        else if(this.getSpeed() >= 120 && this.getSpeed() < 160){
            this.gear = 3;
        }
        else{
            this.gear = 4;
        }
    }
    
    public int getMetros(){
        return this.metros;
    }
    
    public void getStatus(){
        System.out.println("\n\t ID: " + this.getID());
        System.out.println("\t Velocidade: " + this.getSpeed());
        System.out.println("\t Marcha: " + this.getGear());
        System.out.println("\t Metros Percorridos: " + this.getMetros());
        System.out.println("\t POSICAO: " + this.getPosicao());
    }
    
    public void setPosicao(int posicao){
        if(posicao == 0){
            System.out.println("\t EMPATADO");
        }
        this.posicao = posicao;
    }
    
    public int getPosicao(){
        return this.posicao;
    }
    
    public static void main(String[] args){
        
        Scanner userInput = new Scanner(System.in);
        
        Motorcycle newMoto = new Motorcycle(10, 1);
        
        System.out.println("\t A velocidade da moto 1 é: " + newMoto.getSpeed());
        System.out.println("\t O ID da moto 1 é: " + newMoto.getID());
        System.out.println("\t A marcha da moto 1 é: " + newMoto.getGear());
        
        
        Motorcycle newMoto2 = new Motorcycle();
        newMoto2.setSpeed(100);
        newMoto2.setGear(3);
        
        System.out.println("");
        System.out.println("\t O ID da moto 2 é: " + newMoto2.getID());
        System.out.println("\t A marcha da moto 2 é: " + newMoto2.getGear());
        System.out.println("\t A velocidade da moto 2 é: " + newMoto2.getSpeed());
        
        int rodadas = 3;
        
        while(rodadas > 0){
            
            System.out.print("\n\t Speed Moto1: ");
            int speedToAddMoto1 = userInput.nextInt();
            newMoto.addSpeed(speedToAddMoto1);
            
            System.out.print("\t Speed Moto2: ");
            int speedToAddMoto2 = userInput.nextInt();
            newMoto2.addSpeed(speedToAddMoto2);
            
            if(newMoto.getMetros() > newMoto2.getMetros()){ // PRIMEIRA MOTO EM PRIMEIRO LUGAR
                newMoto.setPosicao(1);
                newMoto2.setPosicao(2);
            }
            else if(newMoto.getMetros() == newMoto2.getMetros()){ // EMPATADOS
                newMoto.setPosicao(0);
                newMoto.setPosicao(0);
            }
            else{ // SEGUNDA MOTO EM PRIMEIRO LUGAR
                newMoto.setPosicao(2);
                newMoto2.setPosicao(1);
            }
            
            newMoto.getStatus();
            newMoto2.getStatus();
            
            rodadas--;
        }
        
        if(newMoto.getMetros() > newMoto2.getMetros()){ // PRIMEIRA MOTO EM PRIMEIRO LUGAR
            System.out.println("\t A MOTO 1 GANHOU A CORRIDA!\n");
        }
        else if(newMoto.getMetros() == newMoto2.getMetros()){ // EMPATADOS
            System.out.println("\t AS MOTOS TERMINARAM EMPATADAS!\n");
        }
        else{ // SEGUNDA MOTO EM PRIMEIRO LUGAR
            System.out.println("\n\t A MOTO 2 GANHOU A CORRIDA!\n");
        }
    }
}
