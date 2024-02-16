<template>
  <div class="content bg">
    <dv-full-screen-container>
      <div class="module-box">
        <div style="flex: 0 1 30%">
          <dv-decoration-10 style="height:5px;margin-top: 2vh;" />

        </div>
        <div style="flex: 0 1 30%">
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
				config: {
					data: [
						{
							name: '南阳',
							value: 167
						},
						{
							name: '周口',
							value: 67
						},
						{
							name: '漯河',
							value: 123
						},
						{
							name: '郑州',
							value: 55
						},
						{
							name: '西峡',
							value: 98
						}
					]
        },
        config2:  {
					points: [
						{
							name: '郑州',
							coordinate: [0.48, 0.35]
						},
						{
							name: '新乡',
							coordinate: [0.52, 0.23]
						},
						{
							name: '焦作',
							coordinate: [0.43, 0.29]
						},
						{
							name: '开封',
							coordinate: [0.59, 0.35]
						},
						{
							name: '许昌',
							coordinate: [0.53, 0.47]
						},
						{
							name: '平顶山',
							coordinate: [0.45, 0.54]
						},
						{
							name: '洛阳',
							coordinate: [0.36, 0.38]
						},
						{
							name: '周口',
							coordinate: [0.62, 0.55]
						},
						{
							name: '漯河',
							coordinate: [0.56, 0.56]
						},
						{
							name: '南阳',
							coordinate: [0.37, 0.66]
						},
						{
							name: '信阳',
							coordinate: [0.55, 0.81]
						},
						{
							name: '驻马店',
							coordinate: [0.55, 0.67]
						},
						{
							name: '济源',
							coordinate: [0.37, 0.29]
						},
						{
							name: '三门峡',
							coordinate: [0.20, 0.36]
						},
						{
							name: '商丘',
							coordinate: [0.76, 0.41]
						},
						{
							name: '鹤壁',
							coordinate: [0.59, 0.18]
						},
						{
							name: '濮阳',
							coordinate: [0.68, 0.17]
						},
						{
							name: '安阳',
							coordinate: [0.59, 0.10]
						}
					],
					lines: [
						{
							source: '新乡',
							target: '郑州'
						},
						{
							source: '焦作',
							target: '郑州'
						},
						{
							source: '开封',
							target: '郑州'
						},
						{
							source: '许昌',
							target: '郑州'
						},
						{
							source: '平顶山',
							target: '郑州'
						},
						{
							source: '洛阳',
							target: '郑州'
						},
						{
							source: '周口',
							target: '郑州'
						},
						{
							source: '漯河',
							target: '郑州'
						},
						{
							source: '南阳',
							target: '郑州'
						},
						{
							source: '信阳',
							target: '郑州'
						},
						{
							source: '驻马店',
							target: '郑州'
						},
						{
							source: '济源',
							target: '郑州'
						},
						{
							source: '三门峡',
							target: '郑州'
						},
						{
							source: '商丘',
							target: '郑州'
						},
						{
							source: '鹤壁',
							target: '郑州'
						},
						{
							source: '濮阳',
							target: '郑州'
						},
						{
							source: '安阳',
							target: '郑州'
						}
					],
					bgImgSrc: require('./img/003.png')
				}
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
