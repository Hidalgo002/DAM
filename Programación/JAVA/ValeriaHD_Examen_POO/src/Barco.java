
enum clase {VELA,PESCA, PASAJEROS};

public class Barco extends Vehiculo {

	private int eslora;
	private int calado;
	private clase clases;
	
	
	public Barco(String marca, String color, String numBastidor, int kilometros, int anioFabricacion, int eslora,
			int calado, clase clases) {
		super(marca, color, numBastidor, kilometros, anioFabricacion);
		this.eslora = eslora;
		this.calado = calado;
		this.clases = clases;
	}


	public int getEslora() {
		return eslora;
	}


	public void setEslora(int eslora) {
		this.eslora = eslora;
	}


	public int getCalado() {
		return calado;
	}


	public void setCalado(int calado) {
		this.calado = calado;
	}


	public clase getClases() {
		return clases;
	}


	public void setClases(clase clases) {
		this.clases = clases;
	}


	@Override
	public String toString() {
		return "Barco [marca=" + marca + ", color=" + color + ", numBastidor=" + numBastidor + ", kilometros="
				+ kilometros + ", anioFabricacion=" + anioFabricacion + ", eslora=" + eslora + ", calado=" + calado
				+ ", clases=" + clases + "]";
	}
	
	
	
}
