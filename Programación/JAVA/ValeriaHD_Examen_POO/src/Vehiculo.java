
public class Vehiculo {
	public String marca;
	public String color;
	public String numBastidor;
	public int kilometros;
	protected int anioFabricacion;
	
	public Vehiculo(String marca, String color, String numBastidor, int kilometros, int anioFabricacion) {
		super();
		this.marca = marca;
		this.color = color;
		this.numBastidor = numBastidor;
		this.kilometros = kilometros;
		this.anioFabricacion = anioFabricacion;
	}

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public String getNumBastidor() {
		return numBastidor;
	}

	public void setNumBastidor(String numBastidor) {
		this.numBastidor = numBastidor;
	}

	public int getKilometros() {
		return kilometros;
	}

	public void setKilometros(int kilometros) {
		this.kilometros = kilometros;
	}

	public int getAnioFabricacion() {
		return anioFabricacion;
	}

	public void setAnioFabricacion(int anioFabricacion) {
		this.anioFabricacion = anioFabricacion;
	}

	@Override
	public String toString() {
		return "Vehiculo [marca=" + marca + ", color=" + color + ", numBastidor=" + numBastidor + ", kilometros="
				+ kilometros + ", anioFabricacion=" + anioFabricacion + "]";
	}
	
	
	
	
	
	
}
