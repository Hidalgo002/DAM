
public class Avion extends Vehiculo {

	private byte motores;
	private double velocidadMax;
	private boolean combate;
	
	
	public Avion(String marca, String color, String numBastidor, int kilometros, int anioFabricacion, byte motores,
			double velocidadMax, boolean combate) {
		super(marca, color, numBastidor, kilometros, anioFabricacion);
		this.motores = motores;
		this.velocidadMax = velocidadMax;
		this.combate = combate;
	}


	public byte getMotores() {
		return motores;
	}


	public void setMotores(byte motores) {
		this.motores = motores;
	}


	public double getVelocidadMax() {
		return velocidadMax;
	}


	public void setVelocidadMax(double velocidadMax) {
		this.velocidadMax = velocidadMax;
	}


	public boolean isCombate() {
		return combate;
	}


	public void setCombate(boolean combate) {
		this.combate = combate;
	}


	@Override
	public String toString() {
		return "Avion [marca=" + marca + ", color=" + color + ", numBastidor=" + numBastidor + ", kilometros="
				+ kilometros + ", anioFabricacion=" + anioFabricacion + ", motores=" + motores + ", velocidadMax="
				+ velocidadMax + ", combate=" + combate + "]";
	}
	
	
	
	
}
