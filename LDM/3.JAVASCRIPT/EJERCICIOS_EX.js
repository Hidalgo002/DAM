let abecedario="abcdefghijklmnñopqrstuvwxyz";

function traduccion(letra){
    let numero=1;
    let bandera=false;

    while(!bandera){
        if(abecedario[numero]===letra){
            bandera=true;
        }else{
            if(abecedario.length===27){
                numero=-1;
                bandera=true;
            }else{
                numero++;
            }
        }
    }
return numero+1;
}

function main(){

}
