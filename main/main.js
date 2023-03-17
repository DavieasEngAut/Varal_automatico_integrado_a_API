function Retrair(){
if (document.getElementById('Retrair').value == "retraindo!"){
  window.alert("Varal Retraindo")
}

}

function Expor(){
  if (document.getElementById('Expor').value == "expondo!"){
    window.alert("Varal Expondo Ao Sol")
  }
  
  }

  function Automatico(){

    if (document.getElementById('Automatico'). value == "automatico"){

      window.alert("Modo Automatico Ativado")
      document.getElementById('Automatico').value = "manual"
      document.getElementById('Automatico').textContent = "MODO MANUAL"

      

    }else{
  
      window.alert("Modo Manual Ativado")
      document.getElementById('Automatico').value = "automatico"
      document.getElementById('Automatico').textContent = "MODO AUTOMATICO"

    }

}   