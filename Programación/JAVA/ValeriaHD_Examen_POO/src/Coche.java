
public class Coche extends Vehiculo {
	
	protected boolean electrico;
	private boolean antiguo;
	
	
	public Coche(String marca, String color, String numBastidor, int kilometros, int anioFabricacion, boolean electrico,
			boolean antiguo) {
		super(marca, color, numBastidor, kilometros, anioFabricacion);
		this.electrico = electrico;
		this.antiguo = antiguo;
	}


	public boolean isElectrico() {
		return electrico;
	}


	public void setElectrico(boolean electrico) {
		this.electrico = electrico;
	}


	public boolean isAntiguo() {
		return antiguo;
	}


	public void setAntiguo(boolean antiguo) {
		this.antiguo = antiguo;
	}


	@Override
	public String toString() {
		return "Coche [marca=" + marca + ", color=" + color + ", numBastidor=" + numBastidor + ", kilometros="
				+ kilometros + ", anioFabricacion=" + anioFabricacion + ", electrico=" + electrico + ", antiguo="
				+ antiguo + "]";
	}


	
	
	
	
}
