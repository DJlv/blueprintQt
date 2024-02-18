<template>
  <div class="content bg">
    <dv-full-screen-container>
      <div class="module-box">
        <div style="flex: 0 1 30%">
          <dv-decoration-10 style="height:5px;margin-top: 2vh;" />
        </div>
        <div style="flex: 0 1 40%">
          <div class="d-flex">
            <dv-decoration-8 style="height:50px;flex: 1;" />
            <div class="tc" style="height:50px;flex: 1">数据中心</div>
            <dv-decoration-8 :reverse="true" style="height:50px;flex: 1" />
          </div>
        </div>
        <div style="flex: 0 1 30%">
          <dv-decoration-10 :reverse="true" style="height:5px;transform: rotateY(180deg);margin-top: 2vh;" />
        </div>
      </div>

      <div class="module-box">
        <div style="flex: 0 1 50%">
          <dv-border-box-11 title="dv-border-box-11"  style="width: 100%;height: 25vh">
            <div>
              <dv-capsule-chart :config="config" style="width:100%;height:25vh;padding-top: 60px;padding-left: 40px;padding-right: 40px;" />
            </div>
          </dv-border-box-11>
          <dv-border-box-11 title="dv-border-box-11"  style="width: 100%;height: 25vh"></dv-border-box-11>

        </div>
        <div style="flex: 0 1 50%">
          <dv-border-box-11 title="dv-border-box-11" style="width: 100%;height: 50vh">
            <dv-flyline-chart-enhanced :config="config2" style="width:100%;height:100%;" />
          </dv-border-box-11>
        </div>
        <div style="flex: 0 1 50%">
          <dv-border-box-11 title="dv-border-box-11"  style="width: 100%;height: 94vh"></dv-border-box-11>
        </div>
      </div>
    </dv-full-screen-container>

  </div>
</template>

<script>
	// @ is an alias to /src
	import HelloWorld from '@/components/HelloWorld.vue'

	export default {
		name: 'HomeView',
		components: {
			HelloWorld
		},
    data() {
			return {
        #{data}
      }
    }
	}
</script>
<style>
  *{
    margin: 0;
    padding: 0;
  }
  .content {
    background: #000000;
    color: white;

    width: 100%;
    height: 100vh;
  }
  .bg {
    background: url("./img/002.png") no-repeat center center;
    background-size: cover;
  }
  .module-box{
    display: flex;
    justify-content: space-between;
    margin: 5px;
  }
  .d-flex{
    display: flex;
  }
  /*标题样式*/
  .tc{
    text-align: center;
    font-size: 40px;
  }
</style>
