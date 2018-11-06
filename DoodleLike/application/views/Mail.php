<!DOCTYPE html>
<html>
  <head lang="fr">
    <meta charset="UTF-8"/>
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('style')?>"/>
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('bootstrap.min')?>"/>
    <title>Créer un sondage</title>
  </head>
    <body>
      <header>
      <br>
      <div class="row w-100">
        <div class="col-md-4">
          <a class="lien" href="/~quernec/PHP/Project_php/"><img class="mx-auto d-lg-block" alt="" src="<?php echo img_url('presentation200.png');?>"/></a>
        </div>
        <div class="col-md-4 offset-4">
          <a class="lien" href="/~quernec/PHP/Project_php/">Mes sondages</a>
          <b style="color:#A6E6FA;">&nbsp;&nbsp;|&nbsp;&nbsp;</b>
          <a class="lien" href="/~quernec/PHP/Project_php/index.php/Control/deconnexion">Deconnexion</a>
        </div>
      </div>
    </header>
        <div class="h-100 ml-auto mr-auto" style="width:35%;margin-top: 2%;">
        <form class="h-100" method="POST">
          <div class="ml-auto mr-auto text-center" style="margin-bottom: 10%;">
            <h3>Ajouter des participants</h3>
            <br>
            <div class="form-group row">
              <div class="ml-auto mr-auto">
                <input type="submit" name="ajoutqqn" value="   " style="<?php echo "background:url(".img_url('+.png').") no-repeat;"?>" />
                <label class="col-form-label"> Ajouter/Enlever </label>
                <input type='submit' name="enleveqqn" value="   " style="<?php echo "background:url(".img_url('-.png').") no-repeat;"?>"/>
              </div>
            </div>
            <?php
            for($i=1;$i<=$this->session->userdata('compteurMail');$i++){?>
              <div class="form-group row">
                <div class="col-md-12">
                  <input type="mail" name="<?php echo "inputmail_".$i ?>" value="<?php echo "".$this->session->userdata('inputmail_'.$i) ?>" class="form-control" placeholder="Insérez une adresse e-mail valide" />
                </div>
              </div>
            <?php
            }?>
            <div class="form-group row">
              <div class="ml-auto mr-auto">
                <br>
                <input type="submit" name="sendmail" class="btn btn-primary" value="Envoyer le mail" />
              </div>
            </div>       
          </div>
        </form>
        </div>
  </body>
</html>

